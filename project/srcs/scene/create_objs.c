#include "minirt.h"

t_sphere	*sphere(t_point3 center, double diameter)
{
	t_sphere	*sp;

	if (!(sp = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	sp->center = center;
	sp->diameter = diameter;
	return (sp);
}

t_plane		*plane(t_point3 center, t_vec3 normal)
{
	t_plane	*pl;

	if (!(pl = (t_plane *)malloc(sizeof(t_plane))))
		return (NULL);
	pl->center = center;
	pl->normal = normal;
	return (pl);
}

t_square	*square(t_point3 center, t_vec3 normal, double length)
{
	t_square	*sq;

	if (!(sq = (t_square *)malloc(sizeof(t_square))))
		return (NULL);
	sq->center = center;
	sq->normal = vunit(normal);
	sq->length = length;
	return (sq);
}

t_cylinder	*cylinder(t_point3 center, t_vec3 normal,
		double diameter, double height)
{
	t_cylinder	*cy;

	if (!(cy = (t_cylinder *)malloc(sizeof(t_cylinder))))
		return (NULL);
	cy->center = center;
	cy->normal = normal;
	cy->diameter = diameter;
	cy->height = height;
	return (cy);
}

t_triangle	*triangle(t_point3 p0, t_point3 p1, t_point3 p2)
{
	t_triangle	*tr;

	if (!(tr = (t_triangle *)malloc(sizeof(t_triangle))))
		return (NULL);
	tr->p0 = p0;
	tr->p1 = p1;
	tr->p2 = p2;
	return (tr);
}
