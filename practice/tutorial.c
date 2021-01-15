#include <mlx.h>
#include <math.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int 			main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 914, "Hello World!");
	img.img = mlx_new_image(mlx, 1920, 914);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	/* square */
	/*
	int i = -1;
	while (++i < 100)
	{
		int j = -1;
		while (++j < 100)
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
	}
	*/
	/* triangle */
	/*
	int i = 0;
	int j = 100;
	while (i < 100 && j > 0)
	{
		int k = i + 2 * j;
		while (k > i)
		{
			my_mlx_pixel_put(&img, k, j, 0x00FF0000);
			k--;
		}
		i++;
		j--;
	}
	*/
	/* circle */
	/*
	int	rad = 100;
	int	i = -101;
	int	point;
	while (++i < 100)
	{
		int	j = -101;
		while (++j < 100)
		{
			point = pow(i, 2) + pow(j, 2);
			if (sqrt(point) <= rad)
				my_mlx_pixel_put(&img, i + 100, j + 100, 0x00FF0000);
		}
	}
	*/
	/* gradation */
	int	r = 0;
	int	b = 0;
	int	color = 0;
	double	i = -1;
	while (++i < 1920)
	{
		double	j = 914;
		int	g = 0;
		while (--j > 0)
		{
			color = r << 16 | g << 8 | b;
			my_mlx_pixel_put(&img, i, 914 - j, color);
			g = j / 914 * 256;
		}
		r = i / 1920 * 256;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
