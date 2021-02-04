#ifndef STRUCTURES_H
# define STRUCTURES_H

/*	common structure	*/
typedef struct	s_vec3			t_vec3;
typedef struct	s_vec3			t_point3;
typedef struct	s_vec3			t_color3;
typedef struct	s_ray			t_ray;
typedef struct	s_hit_record	t_hit_record;

/*	scene structure	*/
typedef struct	s_camera		t_camera;
typedef struct	s_canvas		t_canvas;
typedef	struct	s_scene			t_scene;

/*	object structure	*/
typedef struct	s_sphere		t_sphere;	
typedef	struct	s_plane			t_plane;
typedef	struct	s_triangle		t_triangle;
typedef	struct	s_cylinder		t_cylinder;
typedef struct	s_object		t_object;
typedef	struct	s_light			t_light;

/*	identifier	macro	*/
typedef int						t_bool;
# define FALSE 0
# define TRUE 1

typedef int						t_object_type;
# define SP 0
# define PL 2
# define TR 3
# define CY 4
# define LIGHT_POINT 1

/*	A very small value	*/
# define EPSILON 1e-6

/*	unit of Luminous Flux	*/
# define LUMEN 3

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

struct	s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	double		tmin;
	double		tmax;
	double		t;
	t_bool		front_face;
	t_color3	albedo;
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

struct	s_scene
{
	t_canvas		canvas;
	t_camera		camera;
	t_object		*world;
	t_object		*light;
	t_ray			ray;
	t_hit_record	rec;
};

/*	object structure	*/
struct	s_sphere
{
	t_point3	center;
	double		radius;
	double		radius2;
};

struct	s_plane
{
	t_point3	p;
	t_vec3		normal;
};

struct	s_triangle
{
	t_point3	p0;
	t_point3	p1;
	t_point3	p2;
};

struct	s_cylinder
{
	t_point3	center;
	t_vec3		normal;
	double		diameter;
	double		radius;
	double		radius2;
	double		height;
};

struct	s_object
{
	t_object_type	type;
	void			*element;
	void			*next;
	t_color3		albedo;
};

struct	s_light
{
	t_point3	origin;
	t_color3	light_color;
	double		bright_ratio;
};

#endif
