#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)dst + i) = *((char *)src + i);
		i = i + 1;
		if (*((char *)src + i - 1) == (char)c)
			return ((char *)dst + i);
	}
	return (0);
}
