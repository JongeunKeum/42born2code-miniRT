#include "minirt.h"

t_bool	hit_triangle(t_object *tr_obj, t_ray *ray, t_hit_record *rec)
{
	t_triangle	*tr;

	tr = tr_obj->element;
	tr->edge0 = vminus(tr->p1, tr->p0);
	tr->edge2 = vminus(tr->p0, tr->p2);
	tr->n = vcross(tr->edge0, vmult(tr->edge2, -1));
	tr->denominator = vdot(tr->n, ray->dir);
	if (fabs(tr->denominator) <= EPSILON)
		return (FALSE);
	tr->d = vdot(tr->n, tr->p0) * -1;
	tr->root = -1 * (vdot(tr->n, ray->orig) + tr->d) / tr->denominator;
	if (tr->root < rec->tmin || tr->root > rec->tmax)
		return (FALSE);
	tr->edge1 = vminus(tr->p2, tr->p1);
	tr->p = ray_at(ray, tr->root);
	if (vdot(tr->n, vcross(tr->edge0, vminus(tr->p, tr->p0))) < 0 ||
			vdot(tr->n, vcross(tr->edge1, vminus(tr->p, tr->p1))) < 0 ||
			vdot(tr->n, vcross(tr->edge2, vminus(tr->p, tr->p2))) < 0)
		return (FALSE);
	rec->t = tr->root;
	rec->p = tr->p;
	rec->normal = vunit(tr->n);
	set_face_normal(ray, rec);
	rec->albedo = tr_obj->albedo;
	return (TRUE);
}
