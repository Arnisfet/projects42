#include "libft.h"

static char	*ft_putemptystr(void)
{
	char	*str;

	str = ft_calloc(1, 1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (s == 0)
		return (ft_putemptystr());
	i = ft_strlen(s);
	if (i == 0 || len == 0 || i < start)
		return (ft_putemptystr());
	if (start + len > i)
		len = i - start;
	str = ft_calloc(len + 1, 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i = i + 1;
	}
	return (str);
}
