/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 23:08:13 by jkeum             #+#    #+#             */
/*   Updated: 2021/03/13 00:51:35 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene	*scene_init(void)
{
	t_scene	*scene;

	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
		return (NULL);
	scene->world = NULL;
	scene->light = NULL;
	scene->camera = NULL;
	scene->min_width = 480;
	scene->min_height = 480;
	scene->cnt_r = 0;
	scene->cnt_a = 0;
	scene->cnt_c = 0;
	scene->cnt_l = 0;
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
	mlx_get_screen_size(vars->mlx, &(vars->scene->max_width),
			&(vars->scene->max_height));
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

int		print_err(int err_code, t_vars *vars)
{
	free_list(&vars->scene->camera);
	free_list(&vars->scene->light);
	free_list(&vars->scene->world);
	if (err_code == 0)
		printf("%s\n!!!!! Error: Please check the \".rt\" file.\n\n", C_RED);
	else if (err_code == -1)
		printf("%s\n!!!!! Error: Memory Allocation failed\n\n", C_RED);
	else if (err_code == -2)
		printf("%s\n!!!!! Error: Wrong argument to save as \".bmp\" file.\n",
				C_RED);
	free_scene(vars);
	return (0);
}

int		main(int argc, char *argv[])
{
	t_vars	vars;
	int		err_code;

	if (!(vars.scene = scene_init()))
		return (print_err(-1));
	err_code = 1;
	if (argc == 2)
	{
		if (!check_input_file(argv[1]))
			err_code = 0;
		else
			err_code = minirt(argv[1], &vars);
	}
	else if (argc == 3)
	{
		if (ft_strcmp(argv[1], "--save"))
			err_code = -2;
		else if (!check_input_file(argv[2]))
			err_code = 0;
		else
			err_code = bitmap(argv[2], &vars);
	}
	if (err_code <= 0)
		return (print_err(err_code, vars));
	return (0);
}
