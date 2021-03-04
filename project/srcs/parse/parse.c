#include "minirt.h"

int	info_r(char	**info, t_scene *scene)
{
	if (info[0][1] != '\0' || info[3] != NULL)
		return (-1);
	scene->canvas = canvas(ft_atoi(info[1]), ft_atoi(info[2]));
	return (1);
}

// int	info_a(char **info, t_scene *scene)
// {

// }

int	info_c(char **info, t_scene *scene)
{
	t_point3	orig;
	t_vec3		normal;
	double		degrees;
	char		**element;

	if (info[0][1] != '\0' || info[4] != NULL)
		return (-1);
	element = ft_split(info[1], ',');
	orig = point3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	element = ft_split(info[2], ',');
	normal = point3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	degrees = ft_atod(info[3]);
	scene->camera = camera(&scene->canvas, orig, normal, degrees);
	return (1);
}

int	info_l(char **info, t_scene *scene)
{
	t_point3	position;
	double		bright_ratio;
	t_color3	color;
	char		**element;

	if (info[0][1] != '\0' || info[4] != NULL)
		return (-1);
	element = ft_split(info[1], ',');
	position = point3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	bright_ratio = ft_atod(info[2]);
	element = ft_split(info[3], ',');
	color = color3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	color = vdivide(color, 255.0);
	oadd(&scene->light, object(LIGHT_POINT, light_point(position, color, bright_ratio), color3(0, 0, 0)));
	return (1);
}

int	info_sp(char **info, t_scene *scene, t_object **world)
{
	t_point3	center;
	double		diameter;
	t_color3	color;
	char		**element;

	if (info[0][2] != '\0' || info[4] != NULL)
		return (-1);
	element = ft_split(info[1], ',');
	center = point3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	diameter = ft_atod(info[2]);
	element = ft_split(info[3], ',');
	color = color3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
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

	if (info[0][2] != '\0' || info[4] != NULL)
		return (-1);
	element = ft_split(info[1], ',');
	center = point3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	element = ft_split(info[2], ',');
	normal = vec3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	element = ft_split(info[3], ',');
	color = color3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
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
	char		**element;

	if (info[0][2] != '\0' || info[5] != NULL)
		return (-1);
	element = ft_split(info[1], ',');
	center = point3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	element = ft_split(info[2], ',');
	normal = vec3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	length = ft_atod(info[3]);
	element = ft_split(info[4], ',');
	color = color3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	color = vdivide(color, 255.0);
	oadd(world, object(SQ, square(center, normal, length), color));
	return(1);
}

int	info_cy(char **info, t_scene *scene, t_object **world)
{
	t_point3	center;
	t_vec3		normal;
	t_color3	color;
	char		**element;

	if (info[0][2] != '\0' || info[6] != NULL)
		return (-1);
	element = ft_split(info[1], ',');
	center = point3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	element = ft_split(info[2], ',');
	normal = vec3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	element = ft_split(info[5], ',');
	color = color3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	color = vdivide(color, 255.0);
	oadd(world, object(CY, cylinder(center, normal, ft_atod(info[3]), ft_atod(info[4])), color));
	return (1);
}

int	info_tr(char **info, t_scene *scene, t_object **world)
{
	t_point3	a;
	t_point3	b;
	t_point3	c;
	t_color3	color;
	char		**element;

	if (info[0][2] != '\0' || info[5] != NULL)
		return (-1);
	element = ft_split(info[1], ',');
	a = point3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	element = ft_split(info[2], ',');
	b = point3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	element = ft_split(info[3], ',');
	c = point3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	element = ft_split(info[4], ',');
	color = color3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	color = vdivide(color, 255.0);
	oadd(world, object(TR, triangle(a, b, c), color));
	return (1);
}

int	handle_info(char **info, t_scene *scene)
{
	if (!(check_info_err(info)))
		return (-1);
	if (info[0][0] == 'R')
		info_r(info, scene);
	// else if (info[0][0] == 'A')
	// 	info_a(info, scene);
	else if (info[0][0] == 'c' && info[0][1] == '\0')
		info_c(info, scene);
	else if (info[0][0] == 'l')
		info_l(info, scene);
	else if (!(ft_strncmp(info[0], "sp", 2)))
		info_sp(info, scene, &scene->world);
	else if (!(ft_strncmp(info[0], "pl", 2)))
		info_pl(info, scene, &scene->world);
	else if (!(ft_strncmp(info[0], "sq", 2)))
		info_sq(info, scene, &scene->world);
	else if (!(ft_strncmp(info[0], "cy", 2)))
		info_cy(info, scene, &scene->world);
	else if (!(ft_strncmp(info[0], "tr", 2)))
		info_tr(info, scene, &scene->world);
	else
		return (-1);
	return (1);
}

int	parse_rt(char *argv, t_scene *scene)
{
	int		fd;
	int		ret;
	char	*line;
	char	**info;

	fd = open(argv, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		info = ft_split(line,' ');
		handle_info(info, scene);
		free(line);
		free(info);
	}
	if (ret < 0)
		return (-1);
	return (1);
}
