#ifndef MLX_CNTL_H
# define MLX_CNTL_H

# include "minirt.h"

void	rendering(t_vars *vars);
void	set_mlx(t_vars *vars);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		create_rgb(t_color3 color);
int		get_r(int rgb);
int		get_g(int rgb);
int		get_b(int rgb);

#endif
