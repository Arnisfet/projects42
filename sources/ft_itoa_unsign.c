#include "../includes/ft_printf.h"

static int	ft_itoa_unsign_por(long n)
{
	int	j;

	j = 0;
	while (n > 0)
	{
		n = n / 10;
		j = j + 1;
	}
	return (j);
}

char	*ft_itoa_unsign(long n)
{
	char	*str;
	int		j;

	if (n == 0)
		return (ft_strdup("0"));
	j = ft_itoa_unsign_por(n);
	str = malloc(j + 1);
	if (str == 0)
		return (0);
	str[j] = 0;
	while (n > 0)
	{
		j = j - 1;
		str[j] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
