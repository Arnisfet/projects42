#include "../includes/ft_printf.h"

int	ft_type_p(t_flag *flag, unsigned long long p)
{
	char	*str;
	int		dop;
	int		j;

	if (p == 0)
		str = ft_strdup("0");
	else
		str = ft_str_10to16(p, 1);
	if (str == 0)
		return (0);
	dop = flag->width - ft_strlen(str) - 2;
	if (flag->minus == 0 && dop > 0)
		ft_put_n_char(' ', dop, flag);
	ft_put_n_char('0', 1, flag);
	ft_put_n_char('x', 1, flag);
	j = 0;
	while (str[j] != 0)
		j = j + ft_put_n_char(str[j], 1, flag);
	if (flag->minus == 1 && dop > 0)
		ft_put_n_char(' ', dop, flag);
	free (str);
	return (1);
}
