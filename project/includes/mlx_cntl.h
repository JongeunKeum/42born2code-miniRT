/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_cntl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:16:26 by jkeum             #+#    #+#             */
/*   Updated: 2021/03/11 18:49:49 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_CNTL_H
# define MLX_CNTL_H

void	rendering(t_vars *vars);
int		set_mlx(t_vars *vars);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		create_rgb(t_color3 color);
int		handle_hook(t_vars *vars);

#endif
