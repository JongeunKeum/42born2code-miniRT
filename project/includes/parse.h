/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:13:16 by jkeum             #+#    #+#             */
/*   Updated: 2021/03/11 18:14:22 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

int	parse_rt(char *argv, t_scene *scene);
int	handle_info(char **info, t_scene *scene);
int	info_r(char	**info, t_scene *scene);
int	info_c(char **info, t_scene *scene);
int	info_l(char **info, t_scene *scene);
int	info_sp(char **info, t_scene *scene, t_object **world);
int	info_pl(char **info, t_scene *scene, t_object **world);
int	info_sq(char **info, t_scene *scene, t_object **world);
int	info_cy(char **info, t_scene *scene, t_object **world);
int	info_tr(char **info, t_scene *scene, t_object **world);

int	check_info_err(char **info);
int	check_color(t_color3 color);

int	check_err_r(char **info);
int	check_err_a(char **info);
int	check_err_c(char **info);
int	check_err_l(char **info);
int	check_err_sp(char **info);
int	check_err_pl(char **info);
int	check_err_sq(char **info);
int	check_err_cy(char **info);
int	check_err_tr(char **info);

#endif
