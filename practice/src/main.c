#include <stdio.h>
#include "structures.h"
#include "scene.h"
#include "utils.h"
#include "print.h"
#include "trace.h"

int	main(void)
{
	int			i;
	int			j;
	double		u;
	double		v;
	t_color3	pixel_color;
	t_canvas	canv;
	t_camera	cam;
	t_ray		ray;
	t_object	*world;

	/*	scene setting	*/
	canv = canvas(400, 300);
	cam = camera(&canv, point3(0, 0, 0));

	/*	add SP1 in the world	*/
	world = object(SP, sphere(point3(-2, 0, -5), 2));
	/*	add SP2 in the world	*/
	oadd(&world, (object(SP, sphere(point3(2, 0, -5), 2))));

	/*	rendering	*/
	printf("P3\n%d %d\n255\n", canv.width, canv.height);
	j = canv.height;
	while (--j >= 0)
	{
		i = -1;
		while (++i < canv.width)
		{
			u = (double)i / (canv.width - 1);
			v = (double)j / (canv.height - 1);
			/*	ray from camera origin to pixel	*/
			ray = ray_primary(&cam, u, v);
			pixel_color = ray_color(&ray, world);
			write_color(pixel_color);
		}
	}
	return (0);
}
