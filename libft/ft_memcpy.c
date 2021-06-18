#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	while (i < n)
	{
		*((char *)dst + i) = *((char *)src + i);
		i = i + 1;
	}
	return (dst);
}
