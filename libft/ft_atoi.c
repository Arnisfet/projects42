#include"libft.h"

int	ft_atoi(const char *str)
{
	size_t	n;
	size_t	j;
	int		sign;

	n = 0;
	j = 0;
	sign = 1;
	while ((str[j] > 8 && str[j] < 14) || str[j] == 32)
		j = j + 1;
	if (str[j] == '+' || str[j] == '-')
	{
		if (str[j] == '-')
			sign = -sign;
		j = j + 1;
	}
	while (ft_isdigit(str[j]) != 0)
	{
		n = n * 10 + str[j] - 48;
		j = j + 1;
	}
	if (n > 2147483647 && sign == 1)
		return (-1);
	if (n > 2147483648 && sign == -1)
		return (0);
	return (n * sign);
}
