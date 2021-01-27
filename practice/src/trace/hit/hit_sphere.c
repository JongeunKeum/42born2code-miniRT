#include "structures.h"
#include "utils.h"
#include "trace.h"

/*	The reason for changing the first argument of hit_sphere
	from (t_sphere *) to (t_object *) is that texture and rotation transformation
	will be added to the t_object structure, so I have modified it in advance.	*/
double	hit_sphere(t_object *sp_obj, t_ray *ray, t_hit_record *rec)
{
	t_sphere	*sp;
	t_vec3		oc;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		sqrtd;
	double		root;

	sp = sp_obj->element;
	oc = vminus(ray->orig, sp->center);
	a = vdot(ray->dir, ray->dir);	/*	vlength2(ray->dir);	*/
	half_b = vdot(oc, ray->dir);	/*	Formula for even roots	*/
	c = vdot(oc, oc) - sp->radius2;	/*	vlength2(oc) - sp->radius2;	*/
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	/*	Checks whether there is a root
		between tmin and tmax among two real roots(t),
		and checks the smaller root first	*/
	root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	rec->t = root;
	rec->p = ray_at(ray, root);
	/*	normalized normal vector	*/
	rec->normal = vdivide(vminus(rec->p, sp->center), sp->radius);
	/*	The normal vector of rec and the direction vector of the ray
		are compared and stored as t_bool value,
		whether it is the front or the back.	*/
	set_face_normal(ray, rec);
	rec->albedo = sp_obj->albedo;
	return (TRUE);
}
