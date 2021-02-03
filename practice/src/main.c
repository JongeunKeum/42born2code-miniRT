#include <stdio.h>
#include "structures.h"
#include "scene.h"
#include "utils.h"
#include "print.h"
#include "trace.h"

t_scene	*scene_init(void)
{
	t_scene		*scene;
	t_object	*world;
	t_object	*lights;

	/*	When malloc allocation fails, return NULL was set in practice,
		but appropriate error handling is required.	*/
	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
		return (NULL);
	scene->canvas = canvas(400, 300);
	scene->camera = camera(&scene->canvas, point3(0, 0, 0));
	/*	add SP1 in the world	*/
	world = object(SP, sphere(point3(-2, 0, -10), 2), color3(0.5, 0, 0));
	/*	add SP2 in the world	*/
	oadd(&world, object(SP, sphere(point3(2, 0, -10), 2), color3(0, 0.5, 0)));
	/*	add PL in the world	*/
	oadd(&world, object(PL, plane(point3(0, -20, 0), vec3(0, 1, 0)), color3(0.2, 0.3, 0)));
	oadd(&world, object(PL, plane(point3(0, 30, 0), vec3(0, 1, 0)), color3(0.7, 0.1, 0.3)));
	oadd(&world, object(PL, plane(point3(-30, 0, 0), vec3(1, 0, 0)), color3(0.5, 0.5, 0)));
	oadd(&world, object(PL, plane(point3(30, 0, 0), vec3(1, 0, 0)), color3(0.5, 0.5, 0)));
	oadd(&world, object(PL, plane(point3(0, 0, -50), vec3(0, 0, 1)), color3(0.1, 0.1, 0.7)));
	scene->world = world;
	/*	color3(0, 0, 0) is dummy albedo	*/
	lights = object(LIGHT_POINT, light_point(point3(0, 20, 0), color3(1, 1, 1), 0.5), color3(0, 0, 0));
	scene->light = lights;
	return (scene);
}

int		main(void)
{
	int			i;
	int			j;
	double		u;
	double		v;
	t_color3	pixel_color;
	t_scene		*scene;

	/*	scene setting	*/
	scene = scene_init();

	/*	rendering	*/
	printf("P3\n%d %d\n255\n", scene->canvas.width, scene->canvas.height);
	j = scene->canvas.height;
	while (--j >= 0)
	{
		i = -1;
		while (++i < scene->canvas.width)
		{
			u = (double)i / (scene->canvas.width - 1);
			v = (double)j / (scene->canvas.height - 1);
			/*	ray from camera origin to pixel	*/
			scene->ray = ray_primary(&scene->camera, u, v);
			pixel_color = ray_color(scene);
			write_color(pixel_color);
		}
	}
	return (0);
}
