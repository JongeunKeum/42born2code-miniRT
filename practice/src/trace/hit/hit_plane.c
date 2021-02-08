#include "structures.h"
#include "trace.h"
#include "utils.h"

t_bool	hit_plane(t_object *pl_obj, t_ray *ray, t_hit_record *rec)
{
	t_plane	*pl;
	t_vec3	op;
	double	denominator;
	double	root;

	pl = pl_obj->element;
	op = vminus(pl->p, ray->orig);
	denominator = vdot(ray->dir, pl->normal);
	/*	When the denominator approaches 0, an exception is thrown
		because the ray and the plane are parallel.
		Since the denominator is double type,
		the comparison was not performed as `denominator == 0`,
		but rather as `fabs(denominator) <= EPSILON`.	*/
	if (fabs(denominator) <= EPSILON)
		return (FALSE);
	root = vdot(op, pl->normal) / denominator;
	if (root < rec->tmin || root > rec->tmax)
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vunit(pl->normal);
	set_face_normal(ray, rec);
	rec->albedo = pl_obj->albedo;
	return (TRUE);
}
