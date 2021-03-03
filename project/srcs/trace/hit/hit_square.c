#include "minirt.h"

t_bool	hit_square(t_object *sq_obj, t_ray *ray, t_hit_record *rec)
{
	t_square	*sq;
	t_vec3		op;
	t_point3	p;
	double		denominator;
	double		root;
	t_vec3		n_x;
	t_vec3		n_y;
	t_vec3		cp;
	
	sq = sq_obj->element;
	/*	*/
	op = vminus(sq->center, ray->orig);
	denominator = vdot(ray->dir, sq->normal);
	if (fabs(denominator) <= EPSILON)
		return (FALSE);
	root = vdot(op, sq->normal) / denominator;
	if (root < rec->tmin || root > rec->tmax)
		return (FALSE);
	p = ray_at(ray, root);
	/*	*/
	if (sq->normal.x == 0 && sq->normal.y == 1 && sq->normal.z == 0)
		n_x = vunit(vcross(sq->normal, vec3(1, 0, 0)));
	else
		n_x = vunit(vcross(sq->normal, vec3(0, 1, 0)));
	n_y = vunit(vcross(n_x, sq->normal));
	cp = vminus(p, sq->center);
	if (fabs(vdot(cp, n_x)) > sq->length / 2)
		return (FALSE);
	if (fabs(vdot(cp, n_y)) > sq->length / 2)
		return (FALSE);
	/*	*/
	rec->t = root;
	rec->p = p;
	rec->normal = sq->normal;
	set_face_normal(ray, rec);
	rec->albedo = sq_obj->albedo;
	return (TRUE);
}
