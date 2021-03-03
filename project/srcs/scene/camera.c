#include "minirt.h"

t_camera	camera(t_canvas *canvas, t_point3 orig, t_vec3 normal, double degrees)
{
	t_camera	cam;
	double		focal_len;
	double		viewport_width;
	double		fov;
	t_vec3		n_x;
	t_vec3		n_y;

	fov = (M_PI / 180) * degrees;
	viewport_width = 2.0 * tan(fov);
	focal_len = 1.0;
	cam.orig = orig;
	cam.viewport_w = viewport_width;
	cam.viewport_h = viewport_width / canvas->aspect_ratio;
	if (normal.x == 0 && normal.y == 1 && normal.z == 0)
		n_x = vunit(vcross(vec3(1, 0, 0), normal));
	else
		n_x = vunit(vcross(vec3(0, 1, 0), normal));
	n_y = vunit(vcross(normal, n_x));
	cam.focal_len = focal_len;
	cam.horizontal = vmult(n_x, cam.viewport_w);
	cam.vertical = vmult(n_y, cam.viewport_h);
	cam.left_bottom = vplus(vminus(vminus(cam.orig, vdivide(cam.horizontal, 2)), vdivide(cam.vertical, 2)), vunit(normal));
	return (cam);
}
