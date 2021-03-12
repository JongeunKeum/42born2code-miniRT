/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:30:46 by jkeum             #+#    #+#             */
/*   Updated: 2021/03/11 18:50:22 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void		transform_scene(t_vars *vars)
{
	if (vars->mode->trans == TRANSLATE)
	{
		translate(vars->cur, vars->mode->axis, vars->mode->sign);
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

void		del_flag_in_selected(t_vars *vars)
{
	vars->mode->trans = OFF;
	vars->mode->axis = OFF;
	vars->mode->sign = OFF;
}

static int	handle_keypress(int keycode, t_vars *vars)
{
	keypress_obj(keycode, vars);
	keypress_switch(keycode, vars);
	keypress_transform(keycode, vars);
	keypress_axis(keycode, vars);
	keypress_sign(keycode, vars);
	if (keycode == KEY_ESCAPE)
		close_window(vars);
	print_panel(vars);
	return (1);
}

int			handle_hook(t_vars *vars)
{
	if (!(vars->mode = (t_mode *)malloc(sizeof(t_mode))))
		return (0);
	vars->mode->selected = OFF;
	vars->mode->trans = OFF;
	vars->mode->axis = OFF;
	vars->mode->sign = OFF;
	print_panel(vars);
	mlx_hook(vars->win, 2, 1L << 0, handle_keypress, vars);
	mlx_hook(vars->win, 17, 1L << 17, close_window, vars);
	return (1);
}
