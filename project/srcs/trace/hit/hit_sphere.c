#include "minirt.h"

t_bool	hit_sphere(t_object *sp_obj, t_ray *ray, t_hit_record *rec)
{
	t_sphere	*sp;

	sp = sp_obj->element;
	sp->radius = sp->diameter / 2;
	sp->oc = vminus(ray->orig, sp->center);
	sp->a = vdot(ray->dir, ray->dir);
	sp->half_b = vdot(sp->oc, ray->dir);
	sp->c = vdot(sp->oc, sp->oc) - sp->radius * sp->radius;
	sp->discriminant = sp->half_b * sp->half_b - sp->a * sp->c;
	if (sp->discriminant < 0)
		return (FALSE);
	sp->sqrtd = sqrt(sp->discriminant);
	sp->root = (-sp->half_b - sp->sqrtd) / sp->a;
	if (sp->root < rec->tmin || rec->tmax < sp->root)
	{
		sp->root = (-sp->half_b + sp->sqrtd) / sp->a;
		if (sp->root < rec->tmin || rec->tmax < sp->root)
			return (FALSE);
	}
	rec->t = sp->root;
	rec->p = ray_at(ray, sp->root);
	rec->normal = vdivide(vminus(rec->p, sp->center), sp->radius);
	set_face_normal(ray, rec);
	rec->albedo = sp_obj->albedo;
	return (TRUE);
}
