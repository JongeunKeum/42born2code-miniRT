#ifndef STRUCTURES_H
# define STRUCTURES_H

/*	common structure	*/
typedef struct	s_vec3 t_vec3;
typedef struct	s_vec3 t_point3;
typedef struct	s_vec3 t_color3;
typedef struct	s_ray t_ray;

/*	scene structure	*/
typedef struct	s_camera t_camera;
typedef struct	s_canvas t_canvas;

/*	common structure	*/
struct	s_vec3
{
	double	x;
	double	y;
	double	z;
};

struct	s_ray
{
	t_point3	orig;
	t_vec3		dir;
};

/*	scene structure	*/
struct	s_camera
{
	t_point3	orig;		/*	camera origin	*/
	double		viewport_h;	/*	viewport height(viewport == image plane)	*/
	double		viewport_w;	/*	viewport width	*/
	t_vec3		horizontal;	/*	horizontal length vector	*/
	t_vec3		vertical;	/*	vertical length vector	*/
	double		focal_len;	/*	focal length, distance of camera and viewport	*/
	t_point3	left_bottom;	/*	left bottom point	*/
};

struct	s_canvas
{
	int		width;			/*	canvas width	*/
	int		height;			/*	canvas height	*/
	double	aspect_ratio;	/*	aspect ratio(width and height ratio)	*/
};

#endif
