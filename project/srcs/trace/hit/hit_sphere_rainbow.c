/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere_rainbow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 00:53:51 by jkeum             #+#    #+#             */
/*   Updated: 2021/03/13 00:53:53 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_color3	get_rainbow(t_sphere *sp, t_hit_record *rec)
{
	t_color3	color;
	t_vec3		n;

	n = vunit(vminus(rec->p, sp->center));
	color = vmult(color3(n.x + 1, n.y + 1, n.z + 1), 0.5);
	return (color);
}

t_bool			hit_sphere(t_object *sp_obj, t_ray *ray, t_hit_record *rec)
{
	t_sphere	*sp;

	sp = sp_obj->element;
	sp->radius = sp->diameter / 2;
	sp->oc = vminus(ray->orig, sp->center);
	sp->a = vdot(ray->dir, ray->dir);
	sp->half_b = vdot(sp->oc, ray->dir);
	sp->c = vdot(sp->oc, sp->oc) - sp->radius * sp->radius;
	sp->discriminant = sp->half_b * sp->half_b - sp->a * sp->c;
	if (sp->discriminant < 0)
		return (FALSE);
	sp->sqrtd = sqrt(sp->discriminant);
	sp->root = (-sp->half_b - sp->sqrtd) / sp->a;
	if (sp->root < rec->tmin || rec->tmax < sp->root)
	{
		sp->root = (-sp->half_b + sp->sqrtd) / sp->a;
		if (sp->root < rec->tmin || rec->tmax < sp->root)
			return (FALSE);
	}
	rec->t = sp->root;
	rec->p = ray_at(ray, sp->root);
	rec->normal = vdivide(vminus(rec->p, sp->center), sp->radius);
	set_face_normal(ray, rec);
	rec->albedo = get_rainbow(sp, rec);
	return (TRUE);
}
