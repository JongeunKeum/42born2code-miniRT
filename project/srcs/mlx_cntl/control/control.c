#include "minirt.h"

int		close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	transform_scene(t_vars *vars)
{
	if (vars->mode->trans == TRANSLATE)
	{
		translate(vars->cur, vars->mode->axis vars->mode->sign);
		if (vars->cur->type == CAM)
			make_viewport(vars->cur->element);
	}
	else if (vars->mode->trans == ROTATE)
	{
		rotate(vars->cur, vars->mode->axis, vars->mode->sign);
		if (vars->cur->type == CAM)
			make_viewport(vars->cur->element);
	}
	else if (vars->mode->trans == SCALE)
		scale(vars->cur, vars->mode->sign);
	rendering(vars);
}

void	del_flag_in_selected(t_vars *vars)
{
	vars->mode->trans = OFF;
	vars->mode->axis = OFF;
	vars->mode->sign = OFF;
}

void	del_flag_in_trans(t_vars *vars)
{
	vars->mode->axis = OFF;
	vars->mode->sign = OFF;
}

int		handle_keypress(int keycode, t_vars *vars)
{
	if (keycode == KEY_C || keycode == KEY_L || keycode == KEY_O)
	{
		if (keycode == KEY_C)
		{
			vars->mode->selected = CAM;
			vars->cur = vars->scene->camera;
		}
		else if (keycode == KEY_L)
		{
			vars->mode->selected = LIGHT_POINT;
			vars->cur = vars->scene->light;
		}
		else if (keycode == KEY_O)
		{
			vars->mode->selected = OBJECT;
			vars->cur = vars->scene->world;
		}
		del_flag_in_selected(vars);
	}
	if ((keycode == KEY_N || keycode == KEY_P) && vars->mode->selected != OFF)
	{
		if (keycode == KEY_N)
		{
			if (vars->cur->next != NULL)
				vars->cur = vars->cur->next;
		}
		else if (keycode == KEY_P)
		{
			if (vars->cur->pre != NULL)
				vars->cur = vars->cur->pre;
		}
		if (vars->mode->selected == CAM)
		{
			vars->scene->camera = vars->cur;
			rendering(vars);
		}
		del_flag_in_selected(vars);
	}
	if ((keycode == KEY_T || keycode == KEY_R || keycode == KEY_S) && vars->mode->selected != OFF)
	{
		if (keycode == KEY_T)
			vars->mode->trans = TRANSLATE;
		else if (keycode == KEY_R)
		{
			if (vars->cur->type == PL || vars->cur->type == CY || vars->cur->type == SQ || vars->cur->type == CAM)
				vars->mode->trans = ROTATE;
		}
		else if (keycode == KEY_S)
		{
			if (vars->cur->type == SP || vars->cur->type == SQ || vars->cur->type == CY)
				vars->mode->trans = SCALE;
		}
		del_flag_in_trans(vars);
	}
	if (keycode == KEY_X || keycode == KEY_Y || keycode == KEY_Z)
	{
		check_err_in_axis(vars);
		if (keycode == KEY_X)
			vars->mode->axis = X;
		else if (keycode == KEY_Y)
			vars->mode->axis = Y;
		else if (keycode == KEY_Z)
			vars->mode->axis = Z;
		vars->mode->sign = OFF;
	}
	if (keycode == KEY_UP || keycode == KEY_DOWN)
	{
		if (keycode == KEY_UP)
			vars->mode->sign = PLUS;
		else if (keycode == KEY_DOWN)
			vars->mode->sign = MINUS;
		transform_scene(vars);
	}
	if (keycode == KEY_ESCAPE)
		close_window(vars);
	return (1);
}

void	handle_hook(t_vars *vars)
{
	vars->mode = (t_mode *)malloc(sizeof(t_mode));
	mlx_hook(vars->win, 2, 1L<<0, handle_keypress, vars);
	mlx_hook(vars->win, 17, 1L<<17, close_window, vars);
}
