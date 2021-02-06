#include "structures.h"
#include "trace.h"
#include "utils.h"

t_bool	hit_triangle(t_object *tr_obj, t_ray *ray, t_hit_record *rec)
{
	t_triangle	*tr;
	t_vec3		edge0;	/*	p0p1 (p1 - p0)	*/
	t_vec3		edge1;	/*	p1p2 (p2 - p1)	*/
	t_vec3		edge2;	/*	p2p0 (p0 - p2)	*/
	t_vec3		normal;
	t_point3	p;
	double		denominator;
	double		d;
	double		root;
	
	tr = tr_obj->element;
	edge0 = vminus(tr->p1, tr->p0);
	edge2 = vminus(tr->p0, tr->p2);
	normal = vcross(edge0, vmult(edge2, -1));
	denominator = vdot(normal, ray->dir);
	if (fabs(denominator) <= EPSILON)
		return (FALSE);
	d = vdot(normal, tr->p0) * -1;
	root = -1 * (vdot(normal, ray->orig) + d) / denominator;
	if (root < rec->tmin || root > rec->tmax)
		return (FALSE);
	edge1 = vminus(tr->p2, tr->p1);
	p = ray_at(ray, root);
	if (vdot(normal, vcross(edge0, vminus(p, tr->p0))) < 0)
		return (FALSE);
	if (vdot(normal, vcross(edge1, vminus(p, tr->p1))) < 0)
		return (FALSE);
	if (vdot(normal, vcross(edge2, vminus(p, tr->p2))) < 0)
		return (FALSE);
	rec->t = root;
	rec->p = p;
	rec->normal = vunit(normal);
	set_face_normal(ray, rec);
	rec->albedo = tr_obj->albedo;
	return (TRUE);
}
