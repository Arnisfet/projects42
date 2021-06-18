#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	j;
	char	*s1;

	if (s == 0)
		return (ft_calloc(1, 1));
	s1 = ft_calloc(ft_strlen(s) + 1, 1);
	if (s1 == 0)
		return (0);
	j = 0;
	while (s[j] != 0)
	{
		s1[j] = f(j, s[j]);
		j = j + 1;
	}
	return (s1);
}
