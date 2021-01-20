#include "trace.h"

void	set_face_normal(t_ray *r, t_hit_record *rec)
{
	/*	If the dot product of the direction vector of the ray
		and the normal vector of the intersection point
		is negative, the ray hits the front surface(of the object)
		Because the cos@ value is positive
		if the angle between the two vectors is 0 ~ 90 degrees,
		and the cos@ value is negative if the angle is 90 ~ 180 degrees.	*/
	rec->front_face = vdot(r->dir, rec->normal) < 0;
	/*	If it hits the front side of the ray, it is unchanged
		or the normal is reversed.
		(To always use the ray direction vector and the normal vector
		in the opposite state.)	*/
	rec->normal = (rec->front_face) ? rec->normal : vmult(rec->normal, -1);
}
