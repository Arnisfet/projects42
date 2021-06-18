#include "libft.h"

static char	const	*ft_firstnot(char const *s, char c)
{
	size_t	j;

	j = 0;
	while (s[j] != 0)
	{
		if (s[j] != c)
			return (&s[j]);
		j = j + 1;
	}
	return (0);
}

static size_t	ft_getnbr(char const *s, char c)
{
	size_t	k;

	k = 0;
	while (s != 0)
	{
		s = ft_firstnot(s, c);
		if (s != 0)
		{
			k = k + 1;
			s = ft_strchr(s, c);
		}
	}
	return (k);
}

static void	ft_free(char **p, size_t k)
{
	size_t	j;

	j = 0;
	while (j <= k)
	{
		free(p[j]);
		j = j + 1;
	}
	free(p);
}

static size_t	ft_fillarr(char const *s, char c, char **p)
{
	size_t		k;
	size_t		len;
	char const	*ptr1;

	k = 0;
	while (s != 0)
	{
		s = ft_firstnot(s, c);
		if (s != 0)
		{
			ptr1 = ft_strchr(s, c);
			if (ptr1 == 0)
				len = ft_strlen(s);
			if (ptr1 != 0)
				len = ptr1 - s;
			p[k] = ft_calloc(len + 1, 1);
			if (p[k] == 0)
				return (k);
			ft_memcpy(p[k], s, len);
			k = k + 1;
			s = ptr1;
		}
	}
	p[k] = 0;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	k;

	p = (char **)malloc(sizeof(p) * (ft_getnbr(s, c) + 1));
	if (p == 0)
		return (0);
	k = ft_fillarr(s, c, p);
	if (k != 0)
	{
		ft_free(p, k);
		return (0);
	}
	return (p);
}
