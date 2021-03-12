#include "minirt.h"

void	free_list(t_object **obj)
{
	t_object	*tmp;
	t_object	*cur;

	cur = *obj;
	while (cur->next)
	{
		tmp = cur;
		free(tmp->element);
		cur = cur->next;
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
