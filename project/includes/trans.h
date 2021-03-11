/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:24:12 by jkeum             #+#    #+#             */
/*   Updated: 2021/03/11 18:24:13 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANS_H
# define TRANS_H

void		translate(t_object *obj, int axis, int sign);
t_point3	translate_center(t_point3 center, int axis, int sign);
void		scale(t_object *obj, int sign);
void		rotate(t_object *obj, int axis, int sign);

#endif
