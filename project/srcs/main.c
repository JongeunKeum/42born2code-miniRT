#include "minirt.h"
#include <stdio.h>

t_scene	*scene_init()
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	scene->world = NULL;
	scene->light = NULL;
	return (scene);
}

int main(int argc, char *argv[])
{
	t_vars	vars;

	vars.scene = scene_init();
	parse_rt(argv[1], vars.scene);
	set_mlx(&vars);
	rendering(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
