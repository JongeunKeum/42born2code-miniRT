/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:29:27 by jkeum             #+#    #+#             */
/*   Updated: 2021/03/11 18:29:41 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rendering(t_vars *vars)
{
	int		i;
	int		j;
	double	u;
	double	v;
	int		rgb;

	j = vars->scene->canvas.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < vars->scene->canvas.width)
		{
			u = (double)i / (vars->scene->canvas.width - 1);
			v = (double)j / (vars->scene->canvas.height - 1);
			vars->scene->ray = ray_primary(vars->scene->camera->element, u, v);
			rgb = create_rgb(ray_color(vars->scene));
			my_mlx_pixel_put(vars->img, vars->scene->canvas.width - i - 1,
					vars->scene->canvas.height - j - 1, rgb);
			i++;
		}
		j--;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}
