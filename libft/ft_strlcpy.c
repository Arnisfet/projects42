#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i < dstsize - 1 && (*(src + i) != 0) && dstsize != 0)
	{
		*(dst + i) = *(src + i);
		i = i + 1;
	}
	if (dstsize != 0)
		*(dst + i) = 0;
	while (*(src + i) != 0)
		i = i + 1;
	return (i);
}
