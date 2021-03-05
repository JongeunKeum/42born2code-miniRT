#include "minirt.h"

t_ambient	ambient(double ratio, t_color3 ambient_color)
{
	t_ambient	ambient;

	ambient.ratio = ratio;
	ambient.ambient_color = ambient_color;
	return (ambient);
}
