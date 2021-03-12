/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:09:32 by jkeum             #+#    #+#             */
/*   Updated: 2021/03/13 01:09:34 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

void	free_scene(t_vars *vars);
void	free_list(t_object **obj);
void	free_all(t_vars *vars);
void	free_split(char **str);

#endif
