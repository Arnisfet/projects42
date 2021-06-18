#include "../includes/ft_printf.h"

char	*ft_str_10to16(unsigned long long ptr, int small)
{
	unsigned long long	p;
	int					k;
	char				*str;

	k = 0;
	p = ptr;
	while (p != 0)
	{
		p = p / 16;
		k = k + 1;
	}
	str = malloc(k + 1);
	if (str == 0)
		return (0);
	str[k] = 0;
	while (ptr > 0)
	{
		k = k - 1;
		if (ptr % 16 < 10)
			str[k] = ptr % 16 + 48;
		else
			str[k] = ptr % 16 + 55 + 32 * small;
		ptr = ptr / 16;
	}
	return (str);
}
