#ifndef TRANS_H
# define TRANS_H

# include "minirt.h"

void	translate(t_object *obj, int axis, int sign);
void	scale(t_object *obj, int sign);
void	rotate(t_object *obj, int axis, int sign);

#endif
