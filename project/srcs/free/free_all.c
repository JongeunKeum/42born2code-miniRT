/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 00:53:06 by jkeum             #+#    #+#             */
/*   Updated: 2021/03/13 03:39:09 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_scene(t_vars *vars)
{
	if (vars->scene)
		free(vars->scene);
}

void	free_list(t_object **obj)
{
	t_object	*tmp;
	t_object	*cur;

	if (!obj || !(*obj))
		return ;
	cur = *obj;
	while (cur->next)
		cur = cur->next;
	while (cur->pre)
	{
		tmp = cur;
		free(tmp->element);
		cur = cur->pre;
		free(tmp);
	}
	free(cur->element);
	free(cur);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_all(t_vars *vars)
{
	free_list(&vars->scene->camera);
	free_list(&vars->scene->light);
	free_list(&vars->scene->world);
	free(vars->scene);
	free(vars->img);
	free(vars->mode);
}
