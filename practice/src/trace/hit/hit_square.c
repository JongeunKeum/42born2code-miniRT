#include "structures.h"
#include "trace.h"
#include "utils.h"

t_bool	hit_square(t_object *sq_obj, t_ray *ray, t_hit_record *rec)
{
	t_square	*sq;
	t_vec3		op;
	double		a;
	double		b;
	double		c;
	t_point3	p;
	double		denominator;
	double		root;
	t_point3	sq_p1;
	t_point3	sq_p2;

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
	c = sq->normal.x / sq->normal.y;
	a = 1 + pow(c, 2);
	b = sq->center.x;
	sq_p1.x = b + sqrt(a * sq->length * sq->length) / (a * 2);
	sq_p1.y = (-1) * c * sqrt(sq->length * sq->length * a) / (a * 2) + sq->center.y;
	sq_p1.z = sq->center.z;
	sq_p2.x = b - sqrt(a * sq->length * sq->length) / (a * 2);
	sq_p2.y = c * sqrt(sq->length * sq->length * a) / (a * 2) + sq->center.y;
	sq_p2.z = sq->center.z;
	/*	*/
	if (sq_p1.x < sq_p2.x)
	{
		if (p.x < sq_p1.x - EPSILON || p.x > sq_p2.x + EPSILON)
			return (FALSE);
	}
	else if (sq_p1.x > sq_p2.x)
	{
		if (p.x > sq_p1.x + EPSILON || p.x < sq_p1.x - EPSILON)
			return (FALSE);
	}
	if (sq_p1.y < sq_p2.y)
	{
		if (p.y < sq_p1.y - EPSILON || p.y > sq_p2.y + EPSILON)
			return (FALSE);
	}
	else if (sq_p1.y > sq_p2.y)
	{
		if (p.y > sq_p1.y + EPSILON || p.y < sq_p1.y - EPSILON)
			return (FALSE);
	}
	rec->t = root;
	rec->p = p;
	rec->normal = sq->normal;
	set_face_normal(ray, rec);
	rec->albedo = sq_obj->albedo;
	return (TRUE);
}
