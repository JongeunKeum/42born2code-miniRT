#include "minirt.h"

t_bool	hit_cylinder(t_object *cy_obj, t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;
	t_point3	h;
	t_vec3		h_unit;
	t_vec3		co;	
	t_point3	p;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		sqrtd;
	double		root;
	double		h_range;

	cy = cy_obj->element;
	cy->radius = cy->diameter / 2;
	cy->radius2 = cy->radius * cy->radius;
	h_unit = vunit(cy->normal);
	h = vplus(cy->center, vmult(h_unit, cy->height));
	co = vminus(ray->orig, cy->center);
	a = vdot(ray->dir, ray->dir) - pow(vdot(ray->dir, h_unit), 2);
	half_b = vdot(ray->dir, co) - (vdot(ray->dir, h_unit) * vdot(co, h_unit));
	c = vdot(co, co) - pow(vdot(co, h_unit), 2) - cy->radius2;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
		p = ray_at(ray, root);
		h_range = vdot(vminus(p, cy->center), h_unit);
		if (h_range < 0 || h_range > cy->height)
			return (FALSE);
	}
	else
	{
		p = ray_at(ray, root);
		h_range = vdot(vminus(p, cy->center), h_unit);
		if (h_range < 0 || h_range > cy->height)
		{
			root = (-half_b + sqrtd) / a;
			if (root < rec->tmin || rec->tmax < root)
				return (FALSE);
			p = ray_at(ray, root);
			h_range = vdot(vminus(p, cy->center), h_unit);
			if (h_range < 0 || h_range > cy->height)
				return (FALSE);
		}
	}
	rec->t = root;
	rec->p = p;
	rec->normal = vdivide(vminus(p, vplus(cy->center, vmult(h_unit, h_range))), cy->radius);
	set_face_normal(ray, rec);
	rec->albedo = cy_obj->albedo;
	return (TRUE);
}
