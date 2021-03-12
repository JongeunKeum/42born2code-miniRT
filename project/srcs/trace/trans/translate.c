/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 00:54:45 by jkeum             #+#    #+#             */
/*   Updated: 2021/03/13 00:54:46 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_point3	translate_center(t_point3 center, int axis, int sign)
{
	if (sign == PLUS)
	{
		if (axis == X)
			center.x++;
		else if (axis == Y)
			center.y++;
		else if (axis == Z)
			center.z++;
	}
	else if (sign == MINUS)
	{
		if (axis == X)
			center.x--;
		else if (axis == Y)
			center.y--;
		else if (axis == Z)
			center.z--;
	}
	return (center);
}

static void		translate_tr(t_object *obj, int axis, int sign)
{
	t_triangle *tr;

	tr = obj->element;
	if (sign == PLUS)
		translate_tr_plus(tr, axis);
	else if (sign == MINUS)
		translate_tr_minus(tr, axis);
}

static void		translate_sqlicam(t_object *obj, int axis, int sign)
{
	t_square	*sq;
	t_light		*li;
	t_camera	*cam;

	if (obj->type == SQ)
	{
		sq = obj->element;
		sq->center = translate_center(sq->center, axis, sign);
	}
	else if (obj->type == LIGHT_POINT)
	{
		li = obj->element;
		li->origin = translate_center(li->origin, axis, sign);
	}
	else if (obj->type == CAM)
	{
		cam = obj->element;
		cam->orig = translate_center(cam->orig, axis, sign);
	}
}

static void		translate_sppltrcy(t_object *obj, int axis, int sign)
{
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;

	if (obj->type == SP)
	{
		sp = obj->element;
		sp->center = translate_center(sp->center, axis, sign);
	}
	else if (obj->type == PL)
	{
		pl = obj->element;
		pl->center = translate_center(pl->center, axis, sign);
	}
	else if (obj->type == TR)
		translate_tr(obj, axis, sign);
	else if (obj->type == CY)
	{
		cy = obj->element;
		cy->center = translate_center(cy->center, axis, sign);
	}
}

void			translate(t_object *obj, int axis, int sign)
{
	if (obj->type == SP || obj->type == PL \
	|| obj->type == TR || obj->type == CY)
		translate_sppltrcy(obj, axis, sign);
	else if (obj->type == SQ || obj->type == LIGHT_POINT || obj->type == CAM)
		translate_sqlicam(obj, axis, sign);
}
