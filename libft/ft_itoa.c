#include "libft.h"

static int	ft_getlen(int n)
{
	int	k;

	k = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		k = k + 1;
	while (n !=0)
	{
		n = n / 10;
		k = k + 1;
	}
	return (k);
}

static char	*ft_fillminus(int n, char	*s)
{
	int	k;
	int	j;

	k = ft_getlen(n);
	s[0] = '-';
	s[k - 1] = 48 - (n % 10);
	n = - (n / 10);
	j = 2;
	while (j < k)
	{
		s[k - j] = n % 10 + 48;
		n = n / 10;
		j = j + 1;
	}
	return (s);
}

static char	*ft_fill(int n, char	*s)
{
	int	k;
	int	j;

	k = ft_getlen(n);
	j = 0;
	while (j < k)
	{	
		s[k - j - 1] = n % 10 + 48;
		n = n / 10;
		j = j + 1;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;

	s = ft_calloc(ft_getlen(n) + 1, 1);
	if (s == 0)
		return (0);
	if (n < 0)
		ft_fillminus(n, s);
	else
		ft_fill(n, s);
	return (s);
}
