#include "minirt.h"
#include <stdio.h>

t_scene	*scene_init()
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	scene->world = NULL;
	scene->light = NULL;
	scene->camera = NULL;
	scene->min_width = 480;
	scene->min_height = 480;
	return (scene);
}

int		check_input_file(char *argv)
{
	char	*str;

	str = ft_strrev(argv);
	if (ft_strncmp(str, "tr.", 3))
		return (0);
	str = ft_strrev(argv);
	return (1);
}

void	minirt(char *argv, t_vars *vars)
{
	mlx_get_screen_size(vars->mlx, &vars->scene->max_width, &vars->scene->max_height);
	parse_rt(argv, vars->scene);
	set_mlx(vars);
	rendering(vars);
	handle_hook(vars);
	mlx_loop(vars->mlx);
}

int 	main(int argc, char *argv[])
{
	t_vars	vars;

	vars.scene = scene_init();
	if (argc == 2 && check_input_file(argv[1]))
		minirt(argv[1], &vars);
	else if (argc == 3 && !ft_strcmp(argv[1], "--save") && check_input_file(argv[2]))
		bitmap(argv[2], &vars);
//	else
//		err;
	return (0);
}
