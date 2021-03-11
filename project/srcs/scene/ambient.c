/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:45:28 by jkeum             #+#    #+#             */
/*   Updated: 2021/03/11 18:45:33 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ambient	ambient(double ratio, t_color3 ambient_color)
{
	t_ambient	ambient;

	ambient.ratio = ratio;
	ambient.ambient_color = ambient_color;
	return (ambient);
}
