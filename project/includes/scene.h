#ifndef SCENE_H
# define SCENE_H

# include "minirt.h"

t_canvas	canvas(int	width, int height);
t_camera	*camera(t_canvas *canvas, t_point3 orig, t_vec3 normal, double degrees);	
t_ambient	ambient(double ratio, t_color3 ambient_color);
t_object	*object(t_object_type type, void *element, t_color3 albedo);
t_sphere	*sphere(t_point3 center, double diameter);
t_plane		*plane(t_point3 center, t_vec3 normal);
t_square	*square(t_point3 center, t_vec3 normal, double length);
t_cylinder	*cylinder(t_point3 center, t_vec3 normal, double diameter, double height);
t_triangle	*triangle(t_point3 a, t_point3 b, t_point3 c);
t_light		*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio);

#endif
