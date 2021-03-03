#include "minirt.h"

void	scale_sp(t_object *obj, int sign)
{
	t_sphere	*sp;

	sp = obj->element;
	if (sign == PLUS)
		sp->diameter++;
	else if (sign == MINUS)
		sp->diameter--;
}

void	scale_cy(t_object *obj, int sign)
{
	t_cylinder	*cy;
	double		aspect_ratio;

	cy = obj->element;
	aspect_ratio = cy->diameter / cy->height;
	if (sign == PLUS)
		cy->diameter++;
	else if (sign == MINUS)
		cy->diameter--;
	cy->height = cy->diameter / aspect_ratio;
}

void	scale_sq(t_object *obj, int sign)
{
	t_square	*sq;

	sq = obj->element;
	if (sign == PLUS)
		sq->length++;
	else if (sign == MINUS)
		sq->length--;
}

void	scale(t_object *obj, int sign)
{
	if (obj->type == SP)
		scale_sp(obj, sign);
	else if (obj->type == CY)
		scale_cy(obj, sign);
	else if (obj->type == SQ)
		scale_sq(obj, sign);
}
