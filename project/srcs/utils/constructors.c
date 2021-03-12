#include "minirt.h"

t_vec3		vec3(double x, double y, double z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_point3	point3(double x, double y, double z)
{
	t_point3	p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

t_point3	color3(double r, double g, double b)
{
	t_color3	color;

	color.x = r;
	color.y = g;
	color.z = b;
	return (color);
}
