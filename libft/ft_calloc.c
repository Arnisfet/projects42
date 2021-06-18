#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	j;
	void	*p;

	j = 0;
	p = malloc(count * size);
	if (p == 0)
		return (0);
	while (j < count * size)
	{
		*((char *)p + j) = '\0';
		j = j + 1;
	}
	return (p);
}
