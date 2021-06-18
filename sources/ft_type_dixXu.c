#include "../includes/ft_printf.h"

static int	ft_put_precision(int minus, int len, t_flag *flag)
{
	if (len - minus >= flag->precision)
		return (0);
	ft_put_n_char('-', minus, flag);
	ft_put_n_char('0', flag->precision - len + minus, flag);
	return (minus);
}

static int	ft_put_width_before(int minus, int len, t_flag *flag)
{
	if (len < flag->precision + minus)
		len = flag->precision + minus;
	if (flag->width <= len)
		return (0);
	if (flag->zero == 1)
	{
		ft_put_n_char('-', minus, flag);
		ft_put_n_char('0', flag->width - len, flag);
		return (minus);
	}
	if (flag->minus == 0)
	{
		ft_put_n_char(' ', flag->width - len, flag);
		return (0);
	}
	return (0);
}

static void	ft_put_width_after(int minus, int len, t_flag *flag)
{
	if (flag->minus == 0)
		return ;
	if (len < flag->precision + minus)
		len = flag->precision + minus;
	if (flag->width > len)
		ft_put_n_char(' ', flag->width - len, flag);
}

int	ft_type_di(t_flag *flag, int d)
{
	char	*str;
	size_t	j;
	int		minus;

	if (flag->precision >= 0)
		flag->zero = 0;
	if (d == 0 && flag->precision == 0)
		return (ft_put_n_char(' ', flag->width, flag));
	str = ft_itoa(d);
	if (str == 0)
		return (0);
	minus = 0;
	if (str[0] == '-')
		minus = 1;
	j = ft_put_width_before(minus, ft_strlen(str), flag);
	j = j + ft_put_precision(minus, ft_strlen(str), flag);
	while (j < ft_strlen(str))
		j = j + ft_put_n_char(str[j], 1, flag);
	ft_put_width_after(minus, ft_strlen(str), flag);
	free (str);
	return (1);
}

int	ft_type_xXu(t_flag *flag, long n, char c)
{
	char	*str;
	size_t	j;

	if (n < 0)
		n = n + 4294967296;
	if (flag->precision >= 0)
		flag->zero = 0;
	if (flag->precision < 0)
		flag->precision = 1;
	if (n == 0 && flag->precision == 0)
		return (ft_put_n_char(' ', flag->width, flag));
	if (c == 'x' || c == 'X')
		str = ft_str_10to16(n, c / 100);
	if (c == 'u')
		str = ft_itoa_unsign(n);
	if (str == 0)
		return (0);
	ft_put_width_before(0, ft_strlen(str), flag);
	ft_put_precision(0, ft_strlen(str), flag);
	j = 0;
	while (j < ft_strlen(str))
		j = j + ft_put_n_char(str[j], 1, flag);
	ft_put_width_after(0, ft_strlen(str), flag);
	free (str);
	return (1);
}
