#include "trace.h"

/*	ray constructor	*/
t_ray		ray(t_point3 orig, t_vec3 dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = vunit(dir);
	return (ray);
}

/*	primary ray constructor	*/
t_ray		ray_primary(t_camera *cam, double u, double v)
{
	t_ray	ray;

	ray.orig = cam->orig;
	/*	left_bottom + (u * horizontal) + (v * vertical) - origin. and its unit vetor	*/
	ray.dir = vunit(vminus(vplus(vplus(cam->left_bottom, vmult(cam->horizontal, u)), vmult(cam->vertical, v)), cam->orig));
	return (ray);
}

/*	A point separated by the ray(direction vector) 'dir * t' from the ray origin point.	*/
t_point3		ray_at(t_ray *ray, double t)
{
	t_point3	at;

	at = vplus(ray->orig, vmult(ray->dir, t));
	return (at);
}

t_hit_record	record_init(void)
{
	t_hit_record	record;

	record.tmin = EPSILON;
	record.tmax = INFINITY;
	return (record);
}

/*	Returns the color value of the pixel finally obtained by the ray.	*/
t_color3		ray_color(t_scene *scene)
{
	double			t;

	scene->rec = record_init();
	/* If ray hits the sphere
	   (If the ray and sphere have an intersection
	   and the intersection is in front of the camera)	*/
	if (hit(scene->world, &scene->ray, &scene->rec))
		return (vmult(vplus(scene->rec.normal, color3(1, 1, 1)), 0.5));
	else
	{
	/* Coefficient to give gradient based on ray->dir.y value.	*/
	/* Set the range of t value from 0 to 1.	*/
		t = 0.5 * (scene->ray.dir.y + 1.0);
	/*	((1 - t) * white) + (t * blue)	*/
	/*	parametric function	*/
		return (vplus(vmult(color3(1, 1, 1), 1.0 - t), vmult(color3(0.5, 0.7, 1.0), t)));
	}
}
