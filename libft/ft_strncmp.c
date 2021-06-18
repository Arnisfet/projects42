#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (ft_memcmp(s1 + i, s2 + i, 1) != 0)
			return (ft_memcmp(s1 + i, s2 + i, 1));
		if (s1[i] == 0)
			return (0);
		i = i + 1;
	}
	return (0);
}
