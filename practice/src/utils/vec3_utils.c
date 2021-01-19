#include "utils.h"

/*	vec3 constructor	*/
t_vec3		vec3(double x, double y, double z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

/*	point3 constructor	*/
t_point3	point3(double x, double y, double z)
{
	t_point3	p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

/*	color3	constructor	*/
t_point3	color3(double r, double g, double b)
{
	t_color3	color;

	color.x = r;
	color.y = g;
	color.z = b;
	return (color);
}

/*	set vector value	*/
void		vset(t_vec3 *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

/*	the power of vector length	*/
double		vlength2(t_vec3 vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

/*	vector length	*/
double		vlength(t_vec3 vec)
{
	return (sqrt(vlength2(vec)));
}

t_vec3		vplus(t_vec3 v1, t_vec3 v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

t_vec3		vplus_(t_vec3 vec, double x, double y, double z)
{
	vec.x += x;
	vec.y += y;
	vec.z += z;
	return (vec);
}

t_vec3		vminus(t_vec3 v1, t_vec3 v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}

t_vec3		vminus_(t_vec3 v1, double x, double y, double z)
{
	v1.x -= x;
	v1.y -= y;
	v1.z -= z;
	return (v1);
}

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

double		vdot(t_vec3 v1, t_vec3 v2)
{
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

t_vec3		vcross(t_vec3 v1, t_vec3 v2)
{
	t_vec3	r;

	r.x = (v1.y * v2.z) - (v1.z * v2.y);
	r.y = (v1.z * v2.x) - (v1.x * v2.z);
	r.z = (v1.x * v2.y) - (v1.y * v2.x);
	return (r);
}

t_vec3		vunit(t_vec3 v)
{
	double	len;

	len = vlength(v);
	if (len == 0)
	{
		printf("Error\n:Devider is 0");
		exit(0);
	}
	v.x /= len;
	v.y /= len;
	v.z /= len;
	return (v);
}
