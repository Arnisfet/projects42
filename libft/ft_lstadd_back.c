#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (new == 0 || lst == 0)
		return ;
	if (*lst == 0)
	{
		ft_lstadd_front(lst, new);
		return ;
	}
	p = ft_lstlast(*lst);
	p->next = new;
}
