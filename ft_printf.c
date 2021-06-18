#include "includes/ft_printf.h"

int	ft_put_n_char(char c, int n, t_flag *flag)
{
	int	j;

	j = 0;
	while (j < n)
	{
		write(1, &c, 1);
		flag->counter = flag->counter + 1;
		j = j + 1;
	}
	return (j);
}

static void	ft_set_flag(t_flag *flag)
{
	flag->minus = 0;
	flag->zero = 0;
	flag->width = 0;
	flag->precision = -1;
	return ;
}

static int	ft_parser(char	*str, va_list arg)
{
	int		j;
	t_flag	*flag;

	j = 0;
	flag = malloc(sizeof(t_flag));
	if (flag == 0)
		return (0);
	flag->counter = 0;
	while (str[j] != 0)
	{
		if (str[j] != '%')
			j = j + ft_put_n_char(str[j], 1, flag);
		else
		{
			ft_set_flag(flag);
			j = j + 1 + ft_parse_flags(&str[j + 1], flag, arg);
		}		
	}
	j = flag->counter;
	free (flag);
	return (j);
}

int	ft_printf(const char *s, ...)
{
	char	*str;
	int		counter;
	va_list	arg;

	str = ft_strdup(s);
	va_start (arg, s);
	counter = ft_parser(str, arg);
	va_end(arg);
	free (str);
	return (counter);
}
