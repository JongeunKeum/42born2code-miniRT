#include "minirt.h"

void		make_viewport(t_camera *camera)
{
	t_vec3	n_x;
	t_vec3	n_y;

	if (camera->normal.x == 0 && camera->normal.y == 1 && camera->normal.z == 0)
		n_x = vunit(vcross(vec3(1, 0, 0), camera->normal));
	else
		n_x = vunit(vcross(vec3(0, 1, 0), camera->normal));
	n_y = vunit(vcross(camera->normal, n_x));
	camera->horizontal = vmult(n_x, camera->viewport_w);
	camera->vertical = vmult(n_y, camera->viewport_h);
	camera->left_bottom = vplus(vminus(vminus(camera->orig, vdivide(camera->horizontal, 2)), vdivide(camera->vertical, 2)), vunit(camera->normal));
}

t_camera	*camera(t_canvas *canvas, t_point3 orig, t_vec3 normal, double degrees)
{
	t_camera	*cam;
	double		viewport_width;
	double		fov;

	cam = (t_camera *)malloc(sizeof(t_camera));
	fov = (M_PI / 180) * degrees;
	viewport_width = 2.0 * tan(fov);
	cam->focal_len = 1.0;
	cam->orig = orig;
	cam->normal = normal;
	cam->viewport_w = viewport_width;
	cam->viewport_h = viewport_width / canvas->aspect_ratio;
	make_viewport(cam);
	return (cam);
}
