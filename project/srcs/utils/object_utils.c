#include "minirt.h"

void	oadd(t_object **list, t_object *new)
{
	t_object	*cur;
	void		*pre;

	if(*list == NULL)
	{
		*list = new;
		new->pre = NULL;
		return ;
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	pre = cur;
	cur->next = new;
	new->pre = pre;
}
