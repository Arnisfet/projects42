#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i = i - 1;
	}
	if (s[0] == (char) c)
		return ((char *)(s));
	return (0);
}
