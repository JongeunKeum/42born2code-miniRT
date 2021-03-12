#include "minirt.h"

t_color3	phong_lighting(t_scene *scene)
{
	t_color3	light_color;
	t_object	*lights;

	light_color = color3(0, 0, 0);
	lights = scene->light;
	while (lights)
	{
		if (lights->type == LIGHT_POINT)
			light_color = vplus(light_color,
					point_light_get(scene, lights->element));
		lights = lights->next;
	}
	return (vmin(vmult_(light_color, scene->rec.albedo), color3(1, 1, 1)));
}

t_vec3		reflect(t_vec3 v, t_vec3 n)
{
	return (vminus(v, vmult(n, vdot(v, n) * 2)));
}

t_bool		in_shadow(t_object *objs, t_ray light_ray, double light_len)
{
	t_hit_record	rec;

	rec.tmin = 0;
	rec.tmax = light_len;
	if (hit(objs, &light_ray, &rec))
		return (TRUE);
	return (FALSE);
}

t_color3	point_light_get(t_scene *scene, t_light *light)
{
	t_phong	p;

	p.light_dir = vminus(light->origin, scene->rec.p);
	p.light_len = vlength(p.light_dir);
	p.light_ray = ray(vplus(scene->rec.p, vmult(scene->rec.normal, EPSILON)),
			p.light_dir);
	if (in_shadow(scene->world, p.light_ray, p.light_len))
		return (color3(0, 0, 0));
	p.light_dir = vunit(p.light_dir);
	p.view_dir = vunit(vmult(scene->ray.dir, -1));
	p.reflect_dir = reflect(vmult(p.light_dir, -1), scene->rec.normal);
	p.kd = fmax(vdot(scene->rec.normal, p.light_dir), 0.0);
	p.ks = 0.5;
	p.ksn = 64;
	p.ambient = vmult(scene->ambient.ambient_color, scene->ambient.ratio);
	p.diffuse = vmult(light->light_color, p.kd);
	p.spec = pow(fmax(vdot(p.view_dir, p.reflect_dir), 0.0), p.ksn);
	p.specular = vmult(vmult(light->light_color, p.ks), p.spec);
	p.brightness = light->bright_ratio * LUMEN;
	return (vmult(vplus(vplus(p.ambient, p.diffuse), p.specular),
				p.brightness));
}
