#include "trans.h"

t_point3	translate_center(t_point3 center, int axis, int sign)
{
    if (sign == PLUS)
    {
        if (axis == X)
            center.x++;
        else if (axis == Y)
            center.y++;
        else if (axis == Z)
            center.z++;
    }
    else if (sign == MINUS)
    {
        if (axis == X)
            center.x--;
        else if (axis == Y)
            center.y--;
        else if (axis == Z)
            center.z--;
    }
	return (center);
}

void    translate_tr(t_object *obj, int axis, int sign)
{
    t_triangle	*tr;

    tr = obj->element;
    if (sign == PLUS)
    {
        if (axis == X)
        {
            tr->p0.x++;
            tr->p1.x++;
            tr->p2.x++;
        }
        else if (axis == Y)
        {
            tr->p0.y++;
            tr->p1.y++;
            tr->p2.y++;
        }
        else if (axis == Z)
        {
            tr->p0.z++;
            tr->p1.z++;
            tr->p2.z++;
        }
    }
    else if (sign == MINUS)
    {
        if (axis == X)
        {
            tr->p0.x--;
            tr->p1.x--;
            tr->p2.x--;
        }
        else if (axis == Y)
        {
            tr->p0.y--;
            tr->p1.y--;
            tr->p2.y--;
        }
        else if (axis == Z)
        {
            tr->p0.z--;
            tr->p1.z--;
            tr->p2.z--;
        }
    }
}

void    translate(t_object *obj, int axis, int sign)
{
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;
	t_square	*sq;

    if (obj->type == SP)
	{
		sp = obj->element;
		sp->center = translate_center(sp->center, axis, sign);
	}
    else if (obj->type == PL)
	{
		pl = obj->element;
		pl->p = translate_center(pl->p, axis, sign);
	}
    else if (obj->type == TR)
		translate_tr(obj, axis, sign);
    else if (obj->type == CY)
	{
		cy = obj->element;
		cy->center = translate_center(cy->center, axis, sign);
	}
    else if (obj->type == SQ)
	{
		sq = obj->element;
		sq->center = translate_center(sq->center, axis, sign);
	}
}
