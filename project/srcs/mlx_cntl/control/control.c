#include "minirt.h"
/*
int		control_light(int keycode, t_vars *vars)
{
	if (keycode == KEY_T)
		mlx_hook(vars->win, 2, 1L<<0, translate, vars);
}
*/
int		translate_camera(int keycode, t_vars *vars)
{
	int	axis;
	int	sign;

	if (keycode == KEY_W)
	{
		axis = Y;
		sign = PLUS;
	}
	else if (keycode == KEY_S)
	{
		axis = Y;
		sign = MINUS;
	}
	else if (keycode == KEY_D)
	{
		axis = X;
		sign = PLUS;
	}
	else if (keycode == KEY_A)
	{
		axis = X;
		sign = MINUS;
	}
	else if (keycode == KEY_Z)
	{
		axis = Z;
		sign = MINUS;
	}
	else if (keycode == KEY_X)
	{
		axis = Z;
		sign = MINUS;
	}
	else if (keycode == KEY_Q)
		return (0);
	vars->scene->camera->orig = translate_center(vars->scene->camera->orig, axis, sign);
	rendering(vars);
	return (1);
}

int		control_camera(int keycode, t_vars *vars)
{
	if (keycode == KEY_T)
		mlx_hook(vars->win, 2, 1L<<0, translate_camera, vars);
//	else if (keycode == KEY_R)

//	else if (keycode == KEY_S)

}

int		select_scene(int keycode, t_vars *vars)
{
	if (keycode == KEY_L)
		mlx_hook(vars->win, 2, 1L<<0, control_light, vars);
	else if (keycode == KEY_C)
		mlx_hook(vars->win, 2, 1L<<0, control_camera, vars);
//	else if (keycode == KEY_O)
}

int		handle_keypress(int keycode, t_vars *vars)
{
	if (keycode == KEY_L || keycode == KEY_C || keycode == KEY_O)
		select_scene(keycode, vars);
}

void	handle_hook(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L<<0, handle_keypress, vars);
}
