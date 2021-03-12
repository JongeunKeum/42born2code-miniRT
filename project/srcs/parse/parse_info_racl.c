#include "minirt.h"

int	info_r(char **info, t_scene *scene)
{
	int width;
	int height;

	if (!check_err_r(info))
		return (0);
	width = ft_atoi(info[1]);
	height = ft_atoi(info[2]);
	if (width < scene->min_width)
		width = scene->min_width;
	if (height < scene->min_height)
		height = scene->min_height;
	if (width > scene->max_width)
		width = scene->max_width;
	if (height > scene->max_height)
		height = scene->max_height;
	scene->canvas = canvas(width, height);
	return (1);
}

int	info_a(char **info, t_scene *scene)
{
	char		**element;
	t_color3	color;

	if (!check_err_a(info))
		return (0);
	element = ft_split(info[2], ',');
	color = color3(ft_atod(element[0]), ft_atod(element[1]),
			ft_atod(element[2]));
	free_split(element);
	if (!check_color(color))
		return (0);
	color = vdivide(color, 255.0);
	scene->ambient = ambient(ft_atod(info[1]), color);
	return (1);
}

int	info_c(char **info, t_scene *scene)
{
	t_point3	orig;
	t_vec3		normal;
	double		degrees;
	char		**element;

	if (!check_err_c(info))
		return (0);
	element = ft_split(info[1], ',');
	orig = point3(ft_atod(element[0]), ft_atod(element[1]),
			ft_atod(element[2]));
	free_split(element);
	element = ft_split(info[2], ',');
	normal = point3(ft_atod(element[0]), ft_atod(element[1]),
			ft_atod(element[2]));
	free_split(element);
	degrees = ft_atod(info[3]);
	oadd(&scene->camera, object(CAM,
				camera(&scene->canvas, orig, normal, degrees),
				color3(0, 0, 0)));
	return (1);
}

int	info_l(char **info, t_scene *scene)
{
	t_point3	position;
	double		bright_ratio;
	t_color3	color;
	char		**element;

	if (!check_err_l(info))
		return (0);
	element = ft_split(info[1], ',');
	position = point3(ft_atod(element[0]), ft_atod(element[1]),
			ft_atod(element[2]));
	free_split(element);
	bright_ratio = ft_atod(info[2]);
	element = ft_split(info[3], ',');
	color = color3(ft_atod(element[0]), ft_atod(element[1]),
			ft_atod(element[2]));
	free_split(element);
	if (!check_color(color))
		return (0);
	color = vdivide(color, 255.0);
	oadd(&scene->light, object(LIGHT_POINT,
				light_point(position, color, bright_ratio),
				color3(0, 0, 0)));
	return (1);
}
