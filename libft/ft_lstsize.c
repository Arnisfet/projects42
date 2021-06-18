#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	j;

	j = 0;
	while (lst)
	{
		j = j + 1;
		lst = lst->next;
	}
	return (j);
}
