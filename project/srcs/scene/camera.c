/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 23:26:07 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/02 23:56:02 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	cam.horizontal = vmul(n_x, cam.viewport_w);
	cam.vertical = vmul(n_y, cam.viewport_h);
	cam.left_bottom = vsum(vsub(vsub(cam.orig, vdiv(cam.horizontal, 2)), vdiv(cam.vertical, 2)), vunit(normal));
	// t_camera	cam;
	// double		focal_len;
	// double		viewport_height;

	// viewport_height = 2.0;
	// focal_len = 1.0;
	// cam.orig = orig;
	// cam.viewport_h = viewport_height;
	// cam.viewport_w = viewport_height * canvas->aspect_ratio;
	// cam.focal_len = focal_len;
	// cam.horizontal = vec3(cam.viewport_w, 0, 0);
	// cam.vertical = vec3(0, cam.viewport_h, 0);
	// // left_bottom coordinates, origin - (horiaontal / 2) - (vertical / 2) - vec3(0, 0, focal_length)
	// cam.left_bottom = vsub(vsub(vsub(cam.orig, vdiv(cam.horizontal, 2)), vdiv(cam.vertical, 2)), vec3(0, 0, focal_len));

	return (cam);
}
