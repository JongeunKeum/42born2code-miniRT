#include <stdio.h>
#include "structures.h"
#include "scene.h"
#include "utils.h"
#include "print.h"
#include "trace.h"
#include "trans.h"

t_scene	*scene_init(void)
{
	t_scene		*scene;
	t_object	*world;
	t_object	*lights;

	/*	When malloc allocation fails, return NULL was set in practice,
		but appropriate error handling is required.	*/
	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
		return (NULL);
	scene->canvas = canvas(800, 600);
	scene->camera = camera(&scene->canvas, point3(0, 5, 10));
//	world = object(SQ, square(point3(-8, 0, -4), vec3(0, 0, 1), 4), color3(0.7, 0.8, 0.3));
//	world = object(PL, plane(point3(0, -20, 0), vec3(0, 1, 0)), color3(0.2, 0.3, 0));
//	world = object(CY, cylinder(point3(10, 0, -5), vec3(0, 1, 0), 3, 6), color3(0.9, 0, 0.4));
	/*	add SP1 in the world	*/
	world = object(SP, sphere(point3(-2, 0, -7), 4), color3(0.5, 0, 0));
	/*	add SP2 in the world	*/
	oadd(&world, object(SP, sphere(point3(2, 0, -10), 6), color3(0, 0.5, 0)));
	/*	add PL in the world	*/
	oadd(&world, object(PL, plane(point3(0, -20, 0), vec3(0, 1, 0)), color3(0.2, 0.3, 0)));
	oadd(&world, object(PL, plane(point3(0, 20, 0), vec3(0, 1, 0)), color3(0.7, 0.1, 0.3)));
	oadd(&world, object(PL, plane(point3(-30, 0, 0), vec3(1, 0, 0)), color3(0.5, 0.5, 0)));
	oadd(&world, object(PL, plane(point3(30, 0, 0), vec3(1, 0, 0)), color3(0.5, 0.5, 0)));
	oadd(&world, object(PL, plane(point3(0, 0, -40), vec3(0, 0, 1)), color3(0.1, 0.1, 0.7)));
	/*	add TR in the world	*/
	oadd(&world, object(TR, triangle(point3(-7, 2, -2), point3(-2, 2, -5), point3(-4, 7, -3)), color3(0.4, 0, 0.6)));
	/*	add CY in the world	*/
	oadd(&world, object(CY, cylinder(point3(10, 0, -5), vec3(0, 1, 0), 3, 6), color3(0.9, 0, 0.4)));
	/*	add SQ in the world	*/
//	oadd(&world, object(SQ, square(point3(-8, 0, -4), vec3(0, 0, 1), 4), color3(0.7, 0.8, 0.3)));
//	oadd(&world, object(SQ, square(point3(-8, 0, -8), vec3(0, 0, 1), 4), color3(0.7, 0.8, 0.3)));
//	oadd(&world, object(SQ, square(point3(-8, -2, -6), vec3(0, 1, 0), 4), color3(0.7, 0.8, 0.3)));
//	oadd(&world, object(SQ, square(point3(-8, 2, -6), vec3(0, 1, 0), 4), color3(0.7, 0.8, 0.3)));
//	oadd(&world, object(SQ, square(point3(-10, 0, -6), vec3(1, 0, 0), 4), color3(0.7, 0.8, 0.3)));
//	oadd(&world, object(SQ, square(point3(-6, 0, -6), vec3(1, 0, 0), 4), color3(0.7, 0.8, 0.3)));
	oadd(&world, object(SQ, square(point3(-6, 0, -6), vec3(1, 1, 4), 4), color3(0.7, 0.8, 0.3)));
	scene->world = world;
	/*	color3(0, 0, 0) is dummy albedo	*/
	lights = object(LIGHT_POINT, light_point(point3(-3, 15, 5), color3(1, 1, 1), 0.5), color3(0, 0, 0));
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
//	translate(scene->world, Y, PLUS);
//	scale(scene->world, MINUS);
//	rotate(scene->world, X, PLUS);
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
