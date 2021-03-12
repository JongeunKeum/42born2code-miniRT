#include "minirt.h"

static int	check_root(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	cy->root = (-cy->half_b - cy->sqrtd) / cy->a;
	if (cy->root < rec->tmin || rec->tmax < cy->root)
	{
		cy->root = (-cy->half_b + cy->sqrtd) / cy->a;
		if (cy->root < rec->tmin || rec->tmax < cy->root)
			return (0);
		cy->h_len = vdot(vminus(ray_at(ray, cy->root), cy->center), cy->h_unit);
		if (cy->h_len < 0 || cy->h_len > cy->height)
			return (0);
	}
	else
	{
		cy->h_len = vdot(vminus(ray_at(ray, cy->root), cy->center), cy->h_unit);
		if (cy->h_len < 0 || cy->h_len > cy->height)
		{
			cy->root = (-cy->half_b + cy->sqrtd) / cy->a;
			if (cy->root < rec->tmin || rec->tmax < cy->root)
				return (0);
			cy->h_len = vdot(vminus(ray_at(ray, cy->root), cy->center),
					cy->h_unit);
			if (cy->h_len < 0 || cy->h_len > cy->height)
				return (0);
		}
	}
	return (1);
}

t_bool		hit_cylinder(t_object *cy_obj, t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;

	cy = cy_obj->element;
	cy->radius = cy->diameter / 2;
	cy->h_unit = vunit(cy->normal);
	cy->h = vplus(cy->center, vmult(cy->h_unit, cy->height));
	cy->co = vminus(ray->orig, cy->center);
	cy->a = vdot(ray->dir, ray->dir) - pow(vdot(ray->dir, cy->h_unit), 2);
	cy->half_b = vdot(ray->dir, cy->co) - (vdot(ray->dir, cy->h_unit)
			* vdot(cy->co, cy->h_unit));
	cy->c = vdot(cy->co, cy->co) - pow(vdot(cy->co, cy->h_unit), 2)
		- cy->radius * cy->radius;
	cy->discriminant = cy->half_b * cy->half_b - cy->a * cy->c;
	if (cy->discriminant < 0)
		return (FALSE);
	cy->sqrtd = sqrt(cy->discriminant);
	if (!(check_root(cy, ray, rec)))
		return (FALSE);
	rec->t = cy->root;
	rec->p = ray_at(ray, cy->root);
	rec->normal = vdivide(vminus(rec->p, vplus(cy->center,
					vmult(cy->h_unit, cy->h_len))), cy->radius);
	set_face_normal(ray, rec);
	rec->albedo = cy_obj->albedo;
	return (TRUE);
}
