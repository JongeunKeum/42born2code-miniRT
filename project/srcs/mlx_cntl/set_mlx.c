#include "minirt.h"

void	set_mlx(t_vars *vars)
{
	vars->img = (t_img *)malloc(sizeof(t_img));
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "miniRT by jkeum");
	vars->img->img = mlx_new_image(vars->mlx, vars->scene->canvas.width, vars->scene->canvas.height);
	vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bits_per_pixel, &vars->img->line_length, &vars->img->endian);
}
