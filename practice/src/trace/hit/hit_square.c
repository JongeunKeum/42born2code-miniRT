#include "structures.h"
#include "trace.h"
#include "utils.h"

t_bool	hit_square(t_object *sq_obj, t_ray *ray, t_hit_record *rec)
{
	t_square	*sq;
	t_vec3		op;
	t_point3	p;
	t_point3	left_bottom;
	t_point3	right_top;
	t_point3	lb;
	t_point3	rt;
	double		denominator;
	double		root;

	sq = sq_obj->element;
	op = vminus(sq->center, ray->orig);
	denominator = vdot(ray->dir, sq->normal);
	if (fabs(denominator) <= EPSILON)
		return (FALSE);
	root = vdot(op, sq->normal) / denominator;
	if (root < rec->tmin || root > rec->tmax)
		return (FALSE);
	p = ray_at(ray, root);
	left_bottom = vminus(sq->center, vmult(sq->vertex, sq->length / 2));
	right_top = vplus(sq->center, vmult(sq->vertex, sq->length / 2));
	lb = vminus_(left_bottom, EPSILON, EPSILON, EPSILON);
	rt = vplus_(right_top, EPSILON, EPSILON, EPSILON);
	if (p.x < lb.x || p.y < lb.y || p.z < lb.z)
		return (FALSE);
	else if (p.x > rt.x || p.y > rt.y || p.z > rt.z)
		return (FALSE);
	rec->t = root;
	rec->p = p;
	rec->normal = sq->normal;
	set_face_normal(ray, rec);
	rec->albedo = sq_obj->albedo;
	return (TRUE);
}
