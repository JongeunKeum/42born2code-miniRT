/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:06:43 by jkeum             #+#    #+#             */
/*   Updated: 2021/03/13 01:06:44 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	oadd(t_object **list, t_object *new)
{
	t_object	*cur;
	void		*tmp;

	if (*list == NULL)
	{
		*list = new;
		new->pre = NULL;
		return ;
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	tmp = cur;
	cur->next = new;
	new->pre = tmp;
}
