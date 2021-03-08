#include "minirt.h"
#include <stdio.h>

t_scene	*scene_init()
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	scene->world = NULL;
	scene->light = NULL;
	scene->camera = NULL;
	return (scene);
}

int main(int argc, char *argv[])
{
	t_vars	vars;

	vars.scene = scene_init();
	if (argc == 2 && ft_strncmp(ft_strrev(argv[1]), "tr.", 3))
	{
		parse_rt(argv[1], vars.scene);
		set_mlx(&vars);
		rendering(&vars);
		handle_hook(&vars);
		mlx_loop(vars.mlx);
	}
	else if (argc == 3 && ft_strcmp(argv[1], "--save"))
	{
		if (ft_strncmp(ft_strrev(argv[2]), "tr.", 3))
		{
			parse_rt(argv[2], vars.scene);
			rendering_bmp(vars);
		}
	}
//	else
//		err;
	return (0);
}
