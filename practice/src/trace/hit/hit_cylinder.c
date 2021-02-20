#include "structures.h"
#include "utils.h"
#include "trace.h"

t_bool	hit_cylinder(t_object *cy_obj, t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;
	t_point3	h;			/*	The top(center) of the cylinder	*/
	t_vec3		h_unit;		/*	Axis direction vector	*/
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
	/*	cy->center + (h_unit * cy->height)	*/
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
	/*	Check the small root first. When the camera is inside the object.	*/
	if (root < rec->tmin || rec->tmax < root)
	{
		/*	Check the large root.	*/
		root = (-half_b + sqrtd) / a;
		/*	When another object exists
			between the camera and the object currently being inspected.	*/
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
		/*	The camera is inside the object and
			no other object exists between the camera and the object.	*/
		p = ray_at(ray, root);
		h_range = vdot(vminus(p, cy->center), h_unit);
		/*	Check the point P is within the range of the cy->height.	*/
		if (h_range < 0 || h_range > cy->height)
			return (FALSE);
	}
	else	/* When the camera is outside the object.	*/
	{
		p = ray_at(ray, root);
		h_range = vdot(vminus(p, cy->center), h_unit);
		/*	Check the point P is within the range of the cy->height.	*/
		if (h_range < 0 || h_range > cy->height)
		{
			/*	Check the large root.	*/
			root = (-half_b + sqrtd) / a;
			/*	When another object exists
				between the camera and the object currently being inspected.	*/
			if (root < rec->tmin || rec->tmax < root)
				return (FALSE);
			p = ray_at(ray, root);
			h_range = vdot(vminus(p, cy->center), h_unit);
			/*	Check the point P is within the range of the cy->height.	*/
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
