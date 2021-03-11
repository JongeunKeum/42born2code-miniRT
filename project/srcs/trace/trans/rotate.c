#include "minirt.h"

t_vec3	rotate_z(t_vec3 normal, int sign)
{
	t_vec3	result;

	if (sign == PLUS)
	{
		result.x = normal.x * cos(THETA) - normal.y * sin(THETA);
		result.y = normal.x * sin(THETA) + normal.y * cos(THETA);
	}
	else if (sign == MINUS)
	{
		result.x = normal.x * cos(-THETA) - normal.y * sin(-THETA);
		result.y = normal.x * sin(-THETA) + normal.y * cos(-THETA);
	}
	result.z = normal.z;
	return (result);
}

t_vec3	rotate_x(t_vec3 normal, int sign)
{
	t_vec3	result;

	if (sign == PLUS)
	{
		result.y = normal.y * cos(THETA) - normal.z * sin(THETA);
		result.z = normal.y * sin(THETA) + normal.z * cos(THETA);
	}
	else if (sign == MINUS)
	{
		result.y = normal.y * cos(-THETA) - normal.z * sin(-THETA);
		result.z = normal.y * sin(-THETA) + normal.z * cos(-THETA);
	}
	result.x = normal.x;
	return (result);
}

t_vec3	rotate_y(t_vec3 normal, int sign)
{
	t_vec3	result;

	if (sign == PLUS)
	{
		result.z = normal.z * cos(THETA) - normal.x * sin(THETA);
		result.x = normal.z * sin(THETA) + normal.x * cos(THETA);
	}
	else if (sign == MINUS)
	{
		result.z = normal.z * cos(-THETA) - normal.x * sin(-THETA);
		result.x = normal.x * sin(-THETA) + normal.z * cos(-THETA);
	}
	result.y = normal.y;
	return (result);
}

t_vec3	rotate_normal(t_vec3 normal, int axis, int sign)
{
	if (axis == X)
		normal = rotate_x(normal, sign);
	else if (axis == Y)
		normal = rotate_y(normal, sign);
	else if (axis == Z)
		normal = rotate_z(normal, sign);
	return (normal);
}

void	rotate(t_object *obj, int axis, int sign)
{
	t_plane		*pl;
	t_cylinder	*cy;
	t_square	*sq;
	t_camera	*cam;

	if (obj->type == PL)
	{
		pl = obj->element;
		pl->normal = rotate_normal(pl->normal, axis, sign);
	}
	else if (obj->type == CY)
	{
		cy = obj->element;
		cy->normal = rotate_normal(cy->normal, axis, sign);
	}
	else if (obj->type == SQ)
	{
		sq = obj->element;
		sq->normal = rotate_normal(sq->normal, axis, sign);
	}
	else if (obj->type == CAM)
	{
		cam = obj->element;
		cam->normal = rotate_normal(cam->normal, axis, sign);
	}
}
