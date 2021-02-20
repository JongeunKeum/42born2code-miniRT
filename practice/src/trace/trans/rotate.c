#include "trans.h"

t_vec3	rotate_x(t_vec3 normal, int sign)
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

t_vec3	rotate_y(t_vec3 normal, int sign)
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

t_vec3	rotate_z(t_vec3 normal, int sign)
{
	t_vec3	result;

	if (sign == PLUS)
	{
		result.x = normal.z * cos(THETA) - normal.x * sin(THETA);
		result.z = normal.z * sin(THETA) + normal.x * cos(THETA);
	}
	else if (sign == MINUS)
	{
		result.x = normal.z * cos(-THETA) - normal.x * sin(-THETA);
		result.z = normal.x * sin(-THETA) + normal.z * cos(-THETA);
	}
	result.y = normal.y;
	return (result);
}

void	rotate_pl(t_object *obj, int axis, int sign)
{
	t_plane	*pl;

	pl = obj->element;
	if (axis == X)
		pl->normal = rotate_x(pl->normal, sign);
	else if (axis == Y)
		pl->normal = rotate_y(pl->normal, sign);
	else if (axis == Z)
		pl->normal = rotate_z(pl->normal, sign);
}

void	rotate_cy(t_object *obj, int axis, int sign)
{
	t_cylinder	*cy;

	cy = obj->element;
	if (axis == X)
		cy->normal = rotate_x(cy->normal, sign);
	else if (axis == Y)
		cy->normal = rotate_y(cy->normal, sign);
	else if (axis == Z)
		cy->normal = rotate_z(cy->normal, sign);
}

void	rotate_sq(t_object *obj, int axis, int sign)
{
	t_square	*sq;

	sq = obj->element;
	if (axis == X)
		sq->normal = rotate_x(sq->normal, sign);
	else if (axis == Y)
		sq->normal = rotate_y(sq->normal, sign);
	else if (axis == Z)
		sq->normal = rotate_z(sq->normal, sign);
}

void	rotate(t_object *obj, int axis, int sign)
{
	if (obj->type == PL)
		rotate_pl(obj, axis, sign);
	else if (obj->type == CY)
		rotate_cy(obj, axis, sign);
	else if (obj->type == SQ)
		rotate_sq(obj, axis, sign);
}
