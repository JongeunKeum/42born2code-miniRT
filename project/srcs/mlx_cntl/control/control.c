#include "minirt.h"

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
	if (keycode == KEY_C || keycode == KEY_L)
	{
		if (keycode == KEY_C)
			vars->mode->selected = CAM;
		else if (keycode == KEY_L)
			vars->mode->selected = LIGHT_POINT;
		del_flag_in_selected(vars);
	}
	if ((keycode == KEY_T || keycode == KEY_R || keycode == KEY_S) && vars->mode->selected != OFF)
	{
		if (keycode == KEY_T && vars->mode->selected != OFF)
			vars->mode->trans = TRANSLATE;
		else if (keycode == KEY_R && vars->mode->selected != OFF)
			vars->mode->trans = ROTATE;
		else if (keycode == KEY_S && vars->mode->selected != OFF)
			vars->mode->trans = SCALE; 
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
	return (1);
}

void	handle_hook(t_vars *vars)
{
	vars->mode = (t_mode *)malloc(sizeof(t_mode));
	mlx_hook(vars->win, 2, 1L<<0, handle_keypress, vars);
}
