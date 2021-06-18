#include "libft.h"

static char	*ft_putstr(char const *str, size_t j)
{
	char	*p;

	p = ft_calloc(j + 1, 1);
	if (p == 0)
		return (0);
	ft_memcpy(p, str, j);
	return (p);
}

static size_t	ft_trimmerl(char const	*s1, char const *set)
{
	size_t	j;

	j = 0;
	while (s1[j])
	{
		if (ft_strchr(set, s1[j]) == 0)
			return (j);
		j = j + 1;
	}
	return (j);
}

static size_t	ft_trimmerr(char const	*s1, char const *set)
{
	size_t	j;

	j = ft_strlen(s1) - 1;
	while (s1[j])
	{
		if (ft_strchr(set, s1[j]) == 0)
			return (j);
		j = j - 1;
	}
	return (ft_strlen(s1));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	j;
	size_t	k;

	if (s1 == 0)
		return (0);
	if (set == 0 || ft_strlen(s1) == 0)
		return (ft_putstr(s1, ft_strlen(s1)));
	j = ft_trimmerl(s1, set);
	k = ft_trimmerr(s1, set);
	return (ft_putstr(&s1[j], k - j + 1));
}
