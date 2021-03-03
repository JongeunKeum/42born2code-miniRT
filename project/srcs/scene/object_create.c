/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:55:53 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/02 21:54:54 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*object(t_object_type type, void *element, t_color3 albedo)
{
	t_object	*new;

	if (!(new = (t_object *)malloc(sizeof(t_object))))
		return (NULL);
	new->type = type;
	new->element = element;
	new->next = NULL;
	new->albedo = albedo;
	return (new);
}

t_sphere	*sphere(t_point3 center, double diameter)
{
	t_sphere	*sp;

	if (!(sp = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	sp->center = center;
	sp->diameter = diameter;
	return (sp);
}

t_plane		*plane(t_point3 center, t_vec3 normal)
{
	t_plane	*pl;

	if (!(pl = (t_plane *)malloc(sizeof(t_plane))))
		return (NULL);
	pl->center = center;
	pl->normal = normal;
	return (pl);
}

t_square	*square(t_point3 center, t_vec3 normal, double length)
{
	t_square	*sq;

	if (!(sq = (t_square *)malloc(sizeof(t_square))))
		return (NULL);
	sq->center = center;
	sq->normal = vunit(normal);
	sq->length = length;
	return (sq);
}

t_cylinder	*cylinder(t_point3 center, t_vec3 normal, double diameter, double height)
{
	t_cylinder	*cy;

	if (!(cy = (t_cylinder *)malloc(sizeof(t_cylinder))))
		return (NULL);
	cy->center = center;
	cy->normal = normal;
	cy->diameter = diameter;
	cy->height = height;
	return (cy);
}

t_triangle	*triangle(t_point3 a, t_point3 b, t_point3 c)
{
	t_triangle	*tr;
	t_vec3		ab;
	t_vec3		ac;

	if (!(tr = (t_triangle *)malloc(sizeof(t_triangle))))
		return (NULL);
	tr->a = a;
	tr->b = b;
	tr->c = c;
	ab = vsub(b, a);
	ac = vsub(c, a);
	tr->normal = vcross(ab, ac);
	return (tr);
}

t_light		*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio)
{
	t_light	*light;

	if (!(light = (t_light *)malloc(sizeof(t_light))))
		return (NULL);
	light->origin = light_origin;
	light->light_color = light_color;
	light->bright_ratio = bright_ratio;
	return (light);
}
