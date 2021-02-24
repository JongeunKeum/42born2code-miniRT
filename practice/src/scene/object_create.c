#include "scene.h"

t_sphere	*sphere(t_point3 center, double diameter)
{
	t_sphere	*sp;

	if (!(sp = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	sp->center = center;
	sp->diameter = diameter;
	return (sp);
}

t_plane		*plane(t_point3 p, t_vec3 normal)
{
	t_plane	*pl;

	if (!(pl = (t_plane *)malloc(sizeof(t_plane))))
		return (NULL);
	pl->p = p;
	pl->normal = normal;
	return (pl);
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

t_cylinder	*cylinder(t_point3 center, t_vec3 normal, double d, double h)
{
	t_cylinder	*cy;

	if (!(cy = (t_cylinder *)malloc(sizeof(t_cylinder))))
		return (NULL);
	cy->center = center;
	cy->normal = normal;
	cy->diameter = d;
	cy->height = h;
	return (cy);
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

t_object	*object(t_object_type type, void *element, t_color3 albedo)
{
	t_object	*new;

	if (!(new = (t_object *)malloc(sizeof(t_object))))
		return (NULL);
	new->type = type;
	new->element = element;
	new->next = NULL;
	new->albedo = albedo;
	return (new);
}

t_light		*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio)
{
	t_light	*light;

	if (!(light = (t_light *)malloc(sizeof(t_light))))
		return (NULL);
	light->origin = light_origin;
	light->light_color = light_color;
	light->bright_ratio = bright_ratio;
	return (light);
}
