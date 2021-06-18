#include "../includes/ft_printf.h"

int	ft_type_s(t_flag *flag, char *str)
{
	char	*strnull;
	int		len;
	int		j;

	if (str == 0)
	{
		strnull = ft_strdup("(null)");
		if (strnull == 0)
			return (0);
		ft_type_s(flag, strnull);
		free (strnull);
		return (0);
	}
	len = ft_strlen(str);
	if (flag->precision >= 0 && flag->precision < len)
		len = flag->precision;
	if (flag->minus == 0 && flag->width > len)
		ft_put_n_char(' ', flag->width - len, flag);
	j = 0;
	while (j < len)
		j = j + ft_put_n_char(str[j], 1, flag);
	if (flag->minus == 1 && flag->width > len)
		ft_put_n_char(' ', flag->width - len, flag);
	return (1);
}

int	ft_type_c(t_flag *flag, char c)
{
	int	len;

	len = 1;
	if (flag->minus == 0 && flag->width > len)
		ft_put_n_char(' ', flag->width - len, flag);
	ft_put_n_char(c, len, flag);
	if (flag->minus == 1 && flag->width > len)
		ft_put_n_char(' ', flag->width - len, flag);
	return (1);
}

int	ft_type_proc(t_flag *flag)
{
	if (flag->zero == 1 && flag->width > 1)
		ft_put_n_char('0', flag->width - 1, flag);
	if (flag->zero == 0 && flag->minus == 0 && flag->width > 1)
		ft_put_n_char(' ', flag->width - 1, flag);
	ft_put_n_char('%', 1, flag);
	if (flag->minus == 1 && flag->width > 1)
		ft_put_n_char(' ', flag->width - 1, flag);
	return (1);
}
