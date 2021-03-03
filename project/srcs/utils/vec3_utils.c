/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:07:23 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/02 18:39:45 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	vec3(double a, double b, double c)
{
	t_vec3	v;

	v.x = a;
	v.y = b;
	v.z = c;
	return (v);
}

t_point3 point3(double a, double b, double c)
{
	t_point3	p;

	p.x = a;
	p.y = b;
	p.z = c;
	return (p);
}

t_color3 color3(double a, double b, double c)
{
	t_color3	color;

	color.x = a;
	color.y = b;
	color.z = c;
	return (color);
}

void	vset(t_vec3 *vec, double a, double b, double c)
{
	vec->x = a;
	vec->y = b;
	vec->z = c;
}

t_vec3	vsum(t_vec3 a, t_vec3 b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

t_vec3	vsum2(t_vec3 vec, double a, double b, double c)
{
	vec.x += a;
	vec.y += b;
	vec.z += c;
	return (vec);
}

t_vec3	vsub(t_vec3 a, t_vec3 b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}

t_vec3	vsub2(t_vec3 vec, double a, double b, double c)
{
	vec.x -= a;
	vec.y -= b;
	vec.z -= c;
	return (vec);
}

t_vec3	vmul(t_vec3 a, double t)
{
	t_vec3 v;

	v.x = a.x * t;
	v.y = a.y * t;
	v.z = a.z * t;
	return (v);
}

t_vec3	vmulv(t_vec3 a, t_vec3 b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return (a);
}

t_vec3	vdiv(t_vec3 a, double t)
{
	t_vec3 v;

	v.x = a.x / t;
	v.y = a.y / t;
	v.z = a.z / t;
	return (v);
}

double	vdot(t_vec3 a, t_vec3 b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_vec3	vcross(t_vec3 a, t_vec3 b)
{
	t_vec3 v;

	v.x = (a.y * b.z) - (a.z * b.y);
	v.y = (a.z * b.x) - (a.x * b.z);
	v.z = (a.x * b.y) - (a.y * b.x);
	return (v);
}

double	vsize(t_vec3 a)
{
	return (sqrt(pow(a.x, 2.0) + pow(a.y, 2.0) + pow(a.z, 2.0)));
}

t_vec3	vunit(t_vec3 a)
{
	t_vec3	v;
	double	size;

	size = vsize(a);
	v.x = a.x / size;
	v.y = a.y / size;
	v.z = a.z / size;
	return (v);
}

t_vec3	vmin(t_vec3 a, t_vec3 b)
{
	if (a.x > b.x)
		a.x = b.x;
	if (a.y > b.y)
		a.y = b.y;
	if (a.z > b.z)
		a.z = b.z;
	return (a);
}
