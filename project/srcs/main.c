#include "minirt.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	t_vars	vars;

	parse_rt(argv[1], vars.scene);
	set_mlx(&vars);
	rendering(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
