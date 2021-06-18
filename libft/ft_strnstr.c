#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(needle) == 0 && len == 0)
		return ((char *)haystack);
	if (ft_strlen(haystack) < ft_strlen(needle))
		return (0);
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (i <= len - ft_strlen(needle) && len >= ft_strlen(needle))
	{
		if (ft_memcmp(haystack + i, needle, ft_strlen(needle)) == 0)
			return ((char *)haystack + i);
		i = i + 1;
	}
	return (0);
}
