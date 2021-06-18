#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*p1;

	p = *lst;
	*lst = 0;
	p1 = p;
	while (p)
	{
		del(p->content);
		p = p->next;
		free(p1);
		p1 = p;
	}
}
