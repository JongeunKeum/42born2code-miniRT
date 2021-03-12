/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:29:49 by jkeum             #+#    #+#             */
/*   Updated: 2021/03/11 18:30:28 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	set_mlx(t_vars *vars)
{
	if (!(vars->img = (t_img *)malloc(sizeof(t_img))))
		return (0);
	vars->win = mlx_new_window(vars->mlx, vars->scene->canvas.width,
			vars->scene->canvas.height, "miniRT by jkeum");
	vars->img->img = mlx_new_image(vars->mlx, vars->scene->canvas.width,
			vars->scene->canvas.height);
	vars->img->addr = mlx_get_data_addr(vars->img->img,
			&vars->img->bits_per_pixel, &vars->img->line_length,
			&vars->img->endian);
	return (1);
}
