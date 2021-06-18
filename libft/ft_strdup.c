#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;

	dst = malloc(ft_strlen(s1) + 1);
	if (dst == 0)
		return (0);
	return (ft_memmove(dst, s1, ft_strlen(s1) + 1));
}
