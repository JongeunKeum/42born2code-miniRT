/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:12:05 by jkeum             #+#    #+#             */
/*   Updated: 2021/03/11 18:51:01 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_H
# define BITMAP_H

int		bitmap(char *argv, t_vars *vars);
void	save_bitmap(t_vars *vars);
int		set_mlx_bmp(t_vars *vars);

#endif
