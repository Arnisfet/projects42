#include "libft.h"

static size_t	ft_por(size_t n)
{
	size_t	j;

	j = 1;
	while (n >= 10)
	{
		n = n / 10;
		j = j * 10;
	}
	return (j);
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t	nbr;
	size_t	k;
	char	c;

	nbr = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
	}
	k = ft_por(nbr);
	while (k >= 1)
	{
		if (nbr >= k && k != 1)
		{
			c = ((nbr - nbr % k)) / k + 48;
			nbr = nbr % k;
		}
		else
			c = nbr / k + 48;
		write(fd, &c, 1);
		k = k / 10;
	}
}
