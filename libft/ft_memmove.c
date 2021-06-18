#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	int		ovrlap;

	i = 0;
	ovrlap = 0;
	if (dst == 0 && src == 0)
		return (0);
	while (i < len)
	{
		if ((char *)dst == (char *)src + i)
			ovrlap = 1;
		i = i + 1;
	}
	if (ovrlap == 0)
	{
		ft_memcpy(dst, src, len);
		return (dst);
	}
	while (i != 0)
	{
		*((char *)dst + i - 1) = *((char *)src + i - 1);
		i = i - 1;
	}
	return (dst);
}
