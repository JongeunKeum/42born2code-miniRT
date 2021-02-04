#include "structures.h"
#include "utils.h"
#include "trace.h"

t_bool	hit_cylinder(t_object *cy_obj, t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		sqrtd;
	double		root;
	t_point3	axis;

	cy = cy_obj->element;
	a = pow(ray->dir.x, 2) + pow(ray->dir.z, 2);
	half_b = ((ray->orig.x - cy->center.x) * ray->dir.x) + ((ray->orig.z - cy->center.z) * ray->dir.z);
	c = pow(ray->orig.x - cy->center.x, 2) + pow(ray->orig.z - cy->center.z, 2) - cy->radius2;
	discriminant = pow(half_b, 2) - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	rec->t = root;
	rec->p = ray_at(ray, root);
	axis = cy->center;
	axis.y = rec->p.y;
	rec->normal = vdivide(vminus(rec->p, axis), cy->radius);
	set_face_normal(ray, rec);
	rec->albedo = cy_obj->albedo;
	return (TRUE);
}
