#include "minirt.h"

t_bool	hit_square(t_object *sq_obj, t_ray *ray, t_hit_record *rec)
{
	t_square	*sq;

	sq = sq_obj->element;
	sq->op = vminus(sq->center, ray->orig);
	sq->denominator = vdot(ray->dir, sq->normal);
	if (fabs(sq->denominator) <= EPSILON)
		return (FALSE);
	sq->root = vdot(sq->op, sq->normal) / sq->denominator;
	if (sq->root < rec->tmin || sq->root > rec->tmax)
		return (FALSE);
	if (sq->normal.x == 0 && sq->normal.y == 1 && sq->normal.z == 0)
		sq->n_x = vunit(vcross(sq->normal, vec3(1, 0, 0)));
	else
		sq->n_x = vunit(vcross(sq->normal, vec3(0, 1, 0)));
	sq->n_y = vunit(vcross(sq->n_x, sq->normal));
	sq->cp = vminus(ray_at(ray, sq->root), sq->center);
	if (fabs(vdot(sq->cp, sq->n_x)) > sq->length / 2 ||
			fabs(vdot(sq->cp, sq->n_y)) > sq->length / 2)
		return (FALSE);
	rec->t = sq->root;
	rec->p = ray_at(ray, sq->root);
	rec->normal = sq->normal;
	set_face_normal(ray, rec);
	rec->albedo = sq_obj->albedo;
	return (TRUE);
}
