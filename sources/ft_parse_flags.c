#include "../includes/ft_printf.h"

static int	ft_parse_type(char c, t_flag *flag, va_list arg)
{
	if (c == 'd' || c == 'i')
		ft_type_di(flag, va_arg(arg, int));
	if (c == 'p')
		ft_type_p(flag, va_arg(arg, unsigned long long));
	if (c == 'x' || c == 'X' || c == 'u')
		ft_type_xXu(flag, va_arg(arg, long), c);
	if (c == 's')
		ft_type_s(flag, va_arg(arg, char *));
	if (c == 'c')
		ft_type_c(flag, va_arg(arg, int));
	if (c == '%')
		ft_type_proc(flag);
	return (1);
}

static int	ft_getarg(char flagname, t_flag *flag, va_list arg)
{
	if (flagname == 'w')
		flag->width = va_arg(arg, int);
	if (flagname == 'p')
		flag->precision = va_arg(arg, int);
	return (1);
}

static int	ft_getnbr(char *str, char flagname, t_flag *flag)
{
	int		len;
	char	*stritoa;

	len = 0;
	if (ft_isdigit(str[0]) == 0 && flagname == 'p')
	{
		flag->precision = 0;
		return (0);
	}
	while (str[len] == '0' && ft_isdigit(str[len + 1]) == 1)
		len = len + 1;
	if (flagname == 'w')
		flag->width = ft_atoi(str);
	if (flagname == 'p')
		flag->precision = ft_atoi(str);
	stritoa = ft_itoa(ft_atoi(str));
	if (stritoa == 0)
		return (0);
	len = len + ft_strlen(stritoa);
	free (stritoa);
	return (len);
}

static void	ft_correct_flags(t_flag *flag)
{
	if (flag->width < 0)
	{
		flag->width = -flag->width;
		flag->minus = 1;
		flag->zero = 0;
	}
	flag->zero = flag->zero * (1 - flag->minus);
}

int	ft_parse_flags(char *str, t_flag *flag, va_list arg)
{
	int	j;

	j = 0;
	while (str[j] == '-' || str[j] == '0')
	{
		if (str[j] == '-')
			flag->minus = 1;
		if (str[j] == '0')
			flag->zero = 1;
		j = j + 1;
	}
	if (ft_isdigit(str[j]) == 1)
		j = j + ft_getnbr(&str[j], 'w', flag);
	else if (str[j] == '*')
		j = j + ft_getarg('w', flag, arg);
	if (str[j] == '.')
	{
		if (str[j + 1] == '*')
			j = j + ft_getarg('p', flag, arg) + 1;
		else
			j = j + ft_getnbr(&str[j + 1], 'p', flag) + 1;
	}
	ft_correct_flags(flag);
	return (j + ft_parse_type(str[j], flag, arg));
}
