#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include"../libft/libft.h"
# include <stdarg.h>

typedef struct s_flag
{
	int	minus;
	int	zero;
	int	width;
	int	precision;
	int	counter;
}		t_flag;

int		ft_printf(const char *s, ...);
int		ft_put_n_char(char c, int n, t_flag *flag);
int		ft_parse_flags(char *str, t_flag *flag, va_list arg);
char	*ft_str_10to16(unsigned long long ptr, int small);
int		ft_type_di(t_flag *flag, int d);
int		ft_type_p(t_flag *flag, unsigned long long p);
int		ft_type_xXu(t_flag	*flag, long n, char c);
int		ft_type_s(t_flag *flag, char *str);
int		ft_type_c(t_flag *flag, char c);
int		ft_type_proc(t_flag *flag);
char	*ft_itoa_unsign(long n);

#endif
