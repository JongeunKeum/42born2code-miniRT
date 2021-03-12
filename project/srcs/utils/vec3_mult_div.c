#include "minirt.h"

t_vec3		vmult_(t_vec3 v1, t_vec3 v2)
{
	v1.x *= v2.x;
	v1.y *= v2.y;
	v1.z *= v2.z;
	return (v1);
}

t_vec3		vmult(t_vec3 v, double n)
{
	v.x *= n;
	v.y *= n;
	v.z *= n;
	return (v);
}

t_vec3		vdivide(t_vec3 v, double n)
{
	v.x *= 1 / n;
	v.y *= 1 / n;
	v.z *= 1 / n;
	return (v);
}
