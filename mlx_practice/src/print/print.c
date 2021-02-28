#include "print.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_rgb(t_color3 *color)
{
	int	r;
	int	g;
	int	b;

	r = (int)(255.999 * color->x);
	g = (int)(255.999 * color->y);
	b = (int)(255.999 * color->z);
	return (0 << 24 | r << 16 | g << 8 | b);
}

int	get_r(int rgb)
{
	return (rgb >> 16 & 0xFF);
}

int	get_g(int rgb)
{
	return (rgb >> 8 & 0xFF);
}

int	get_b(int rgb)
{
	return (rgb & 0xFF);
}
