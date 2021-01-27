#include "trace.h"

t_color3	phong_lighting(t_scene *scene)
{
	t_color3	light_color;
	t_object	*lights;

	light_color = color3(0, 0, 0);
	lights = scene->light;
	while (lights)
	{
		if (lights->type == LIGHT_POINT)
			light_color = vplus(light_color, point_light_get(scene, lights->element));
		lights = lights->next;
	}
	/*	dprintf(2, "light_color: %f, %f, %f\n", light_color.x, light_color.y, light_color.z);	*/
	return (vmin(vmult_(light_color, scene->rec.albedo), color3(1, 1, 1)));
}

/*	(ambient + diffuse + specular) * objectColor * damping_ratio;
	vec3	lightDir = normalize(lightPos - FragPos);

	## Ambient
	double	ambientStrength = 0.1;
	vec3	ambient = ambientStrength * lightColor;

	## Diffuse
	vec3	norm = normalize(Normal);
	vec3	lightDir = normalize(lightPos - FragPos);
	**	By taking the dot product between the norm vector and the lightDir vector,
	**	we need to calculate the light diffusion effect on the current fragment.
	**	The resulting value is then multiplied by the color of the light
	**	to get the diffuse component.
	**	The larger the angle between the two vectors,
	**	the darker the diffusion component.
	**	If the angle between the two vectors is greater than 90 degree,
	**	the dot product result is negative.
	**	(The diffusion component to be multiplied by result becomes negative.)
	**	For this reason, we will return the larger of the two parameters
	**	(dot product value and 0) so that the diffusion value is not negative.
	double	diff = max(dot(norm, lightDir), 0.0);
	vec3	diffuse = diff * lightColor;

	## Specular
	**	First, define an intensity value to give the specular highlight
	**	a medium light color so that it doesn't affect too much.
	**	If you set the value to 1.0,
	**	you get a specular component that is too bright.
	double	specularStrength = 0.5;
	vec3	viewDir = normalize(viewPos - FragPos);
	**	The reflect function expects the first vector
	**	to point to the position of the piece in the light source,
	**	but the lightDir vector is now in a different direction
	**	(the direction from the piece to the light source,
	**	which depends on the previous subtraction order).
	**	To get the correct reflect vector,
	**	change the direction by first making lightDir negative.
	vec3	reflectDir = reflect(-lightDir, norm);
	**	First, calculate the dot product between the view direction
	**	and the reflection direction(make sure that it is not negative)
	**	and square it by 32. 32 is the shininess value of the highlight.
	**	The higher the degree of glitter of an object,
	**	the smaller the highlight because it reflects the light appropriately
	**	rather than scattering it entiely.
	double	spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	vec3	specular = specularStrength * spec * lightColor;

	vec3	result = (ambient + diffuse + specular) * objectColor;
*/

t_vec3		reflect(t_vec3 v, t_vec3 n)
{
	/*	v - 2 * dot(v, n) * n;	*/
	/*	dot(v, n) means (the length of v)*(cos(theta))	*/
	return (vminus(v, vmult(n, vdot(v, n) * 2)));
}

t_color3	point_light_get(t_scene *scene, t_light *light)
{
	t_color3	ambient;
	t_color3	diffuse;
	t_color3	specular;
	t_vec3		light_dir;
	t_vec3		view_dir;
	t_vec3		reflect_dir;
	double		ka;
	double		kd;
	double		ks;
	double		ksn;
	double		spec;
	double		brightness;

	view_dir = vunit(vmult(scene->ray.dir, -1));
	light_dir = vunit(vminus(light->origin, scene->rec.p));
	reflect_dir = reflect(vmult(light_dir, -1), scene->rec.normal);
	/*	ka : ambient strength	*/
	ka = 0.1;
	/*	kd : diffuse strength	*/
	kd = fmax(vdot(scene->rec.normal, light_dir), 0.0);
	/*	ks : specular strength	*/
	ks = 0.5;
	ksn = 64;
	ambient = vmult(light->light_color, ka);
	diffuse = vmult(light->light_color, kd);
	spec = pow(fmax(vdot(view_dir, reflect_dir), 0.0), ksn);
	specular = vmult(vmult(light->light_color, ks), spec);
	/*	Macro defining reference (luminous flux) / (intensity)	*/
	brightness = light->bright_ratio * LUMEN;
	return (vmult(vplus(vplus(ambient, diffuse), specular), brightness));
}
