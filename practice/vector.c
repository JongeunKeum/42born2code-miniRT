#include <stdio.h>
#include <math.h>

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

t_vector		vector_ctor(double x, double y, double z)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vector		v_add(t_vector v1, t_vector v2)
{
	t_vector	r;

	r.x = v1.x + v2.x;
	r.y = v1.y + v2.y;
	r.z = v1.z + v2.z;
	return (r);
}

t_vector		v_sub(t_vector v1, t_vector v2)
{
	t_vector	r;

	r.x = v1.x - v2.x;
	r.y = v1.y - v2.y;
	r.z = v1.z - v2.z;
	return (r);
}

t_vector		v_mul(t_vector v1, t_vector v2)
{
	t_vector	r;

	r.x = v1.x * v2.x;
	r.y = v1.y * v2.y;
	r.z = v1.z * v2.z;
	return (r);
}

t_vector		n_mul(t_vector v, double n)
{
	t_vector	r;

	r.x = v.x * n;
	r.y = v.y * n;
	r.z = v.z * n;
	return (r);
}

t_vector		n_div(t_vector v, double n)
{
	t_vector	r;

	r.x = v.x / n;
	r.y = v.y / n;
	r.z = v.z / n;
	return (r);
}

double			v_dot(t_vector v1, t_vector v2)
{
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

t_vector		v_cross(t_vector v1, t_vector v2)
{
	t_vector	r;

	r.x = (v1.y * v2.z) - (v1.z * v2.y);
	r.y = (v1.z * v2.x) - (v1.x * v2.z);
	r.z = (v1.x * v2.y) - (v1.y * v2.x);
	return (r);
}

double			v_size(t_vector v)
{
	double	sum;

	sum = pow(v.x, 2.0) + pow(v.y, 2.0) + pow(v.z, 2.0);
	return (sqrt(sum));
}

t_vector		v_unit(t_vector v)
{
	return (n_div(v, v_size(v)));
}

int				main(void)
{
	t_vector	v1;
	t_vector	v2;
	t_vector	v_sum;

	v1 = vector_ctor(1.0, 2.0, 3.0);
	v2 = vector_ctor(3.5, 2.5, 1.5);
	v_sum = v_add(v1, v2);
	printf("x:%f\ny:%f\nz:%f\n", v_sum.x, v_sum.y, v_sum.z);
	return (0);
}
