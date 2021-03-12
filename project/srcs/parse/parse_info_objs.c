#include "minirt.h"

int	info_sp(char **info, t_scene *scene, t_object **world)
{
	t_point3	center;
	double		diameter;
	t_color3	color;
	char		**element;

	if (!check_err_sp(info))
		return (0);
	element = ft_split(info[1], ',');
	center = point3(ft_atod(element[0]), ft_atod(element[1]),
			ft_atod(element[2]));
	free(element);
	diameter = ft_atod(info[2]);
	element = ft_split(info[3], ',');
	color = color3(ft_atod(element[0]), ft_atod(element[1]),
			ft_atod(element[2]));
	free(element);
	if (!check_color(color))
		return (0);
	color = vdivide(color, 255.0);
	oadd(world, object(SP, sphere(center, diameter), color));
	return (1);
}

int	info_pl(char **info, t_scene *scene, t_object **world)
{
	t_point3	center;
	t_vec3		normal;
	t_color3	color;
	char		**element;

	if (!check_err_pl(info))
		return (0);
	element = ft_split(info[1], ',');
	center = point3(ft_atod(element[0]), ft_atod(element[1]),
			ft_atod(element[2]));
	free(element);
	element = ft_split(info[2], ',');
	normal = vec3(ft_atod(element[0]), ft_atod(element[1]),
			ft_atod(element[2]));
	free(element);
	element = ft_split(info[3], ',');
	color = color3(ft_atod(element[0]), ft_atod(element[1]),
			ft_atod(element[2]));
	free(element);
	if (!check_color(color))
		return (0);
	color = vdivide(color, 255.0);
	oadd(world, object(PL, plane(center, normal), color));
	return (1);
}

int	info_sq(char **info, t_scene *scene, t_object **world)
{
	t_point3	center;
	t_vec3		normal;
	double		length;
	t_color3	color;
	char		**elem;

	if (!check_err_sq(info))
		return (0);
	elem = ft_split(info[1], ',');
	center = point3(ft_atod(elem[0]), ft_atod(elem[1]), ft_atod(elem[2]));
	free(elem);
	elem = ft_split(info[2], ',');
	normal = vec3(ft_atod(elem[0]), ft_atod(elem[1]), ft_atod(elem[2]));
	free(elem);
	length = ft_atod(info[3]);
	elem = ft_split(info[4], ',');
	color = color3(ft_atod(elem[0]), ft_atod(elem[1]), ft_atod(elem[2]));
	free(elem);
	if (!check_color(color))
		return (0);
	color = vdivide(color, 255.0);
	oadd(world, object(SQ, square(center, normal, length), color));
	return (1);
}

int	info_cy(char **info, t_scene *scene, t_object **world)
{
	t_point3	center;
	t_vec3		normal;
	t_color3	color;
	char		**element;

	if (!check_err_cy(info))
		return (0);
	element = ft_split(info[1], ',');
	center = point3(ft_atod(element[0]), ft_atod(element[1]),
			ft_atod(element[2]));
	free(element);
	element = ft_split(info[2], ',');
	normal = vec3(ft_atod(element[0]), ft_atod(element[1]),
			ft_atod(element[2]));
	free(element);
	element = ft_split(info[5], ',');
	color = color3(ft_atod(element[0]), ft_atod(element[1]),
			ft_atod(element[2]));
	free(element);
	if (!check_color(color))
		return (0);
	color = vdivide(color, 255.0);
	oadd(world, object(CY, cylinder(center, normal, ft_atod(info[3]),
					ft_atod(info[4])), color));
	return (1);
}

int	info_tr(char **info, t_scene *scene, t_object **world)
{
	t_point3	a;
	t_point3	b;
	t_point3	c;
	t_color3	color;
	char		**elem;

	if (!check_err_tr(info))
		return (0);
	elem = ft_split(info[1], ',');
	a = point3(ft_atod(elem[0]), ft_atod(elem[1]), ft_atod(elem[2]));
	free(elem);
	elem = ft_split(info[2], ',');
	b = point3(ft_atod(elem[0]), ft_atod(elem[1]), ft_atod(elem[2]));
	free(elem);
	elem = ft_split(info[3], ',');
	c = point3(ft_atod(elem[0]), ft_atod(elem[1]), ft_atod(elem[2]));
	free(elem);
	elem = ft_split(info[4], ',');
	color = color3(ft_atod(elem[0]), ft_atod(elem[1]), ft_atod(elem[2]));
	free(elem);
	if (!check_color(color))
		return (0);
	color = vdivide(color, 255.0);
	oadd(world, object(TR, triangle(a, b, c), color));
	return (1);
}
