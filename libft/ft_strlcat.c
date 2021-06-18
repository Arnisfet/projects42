#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	c;

	j = 0;
	i = ft_strlen(dst);
	c = i;
	if (c > dstsize)
		c = dstsize;
	while (i < dstsize - 1 && (*(src + j) != 0) && dstsize != 0)
	{
		*(dst + i) = *(src + j);
		i = i + 1;
		j = j + 1;
	}
	if (dstsize != 0)
		*(dst + i) = 0;
	while (*(src + j) != 0)
		j = j + 1;
	return (j + c);
}
