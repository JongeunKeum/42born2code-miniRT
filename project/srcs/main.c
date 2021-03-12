#include "minirt.h"

t_scene	*scene_init()
{
	t_scene	*scene;

	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
		return (NULL);
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

int		minirt(char *argv, t_vars *vars)
{
	vars->mlx = mlx_init();
	mlx_get_screen_size(vars->mlx, &(vars->scene->max_width), &(vars->scene->max_height));
	if (!(parse_rt(argv, vars->scene)))
		return (0);
	if (!(set_mlx(vars)))
		return (-1);
	rendering(vars);
	if (!(handle_hook(vars)))
		return (-1);
	mlx_loop(vars->mlx);
	return (1);
}

int	print_err(int err_code)
{
	if (err_code == 0)
		printf("%s\n!!!!! Error in '.rt' file, Please check the file.\n\n", C_RED);
	else if (err_code == -1)
		printf("%s\n!!!!! Error in memory allocation.\n\n", C_RED);
	return (0);
}

int 	main(int argc, char *argv[])
{
	t_vars	vars;
	int		err_code;

	if(!(vars.scene = scene_init()))
		return (print_err(-1));
	if (argc == 2 && check_input_file(argv[1]))
		err_code = minirt(argv[1], &vars);
	else if (argc == 3 && !ft_strcmp(argv[1], "--save") && check_input_file(argv[2]))
		err_code = bitmap(argv[2], &vars);
	if (err_code == 0 || err_code == -1)
		return (print_err(err_code));
	return (0);
}
