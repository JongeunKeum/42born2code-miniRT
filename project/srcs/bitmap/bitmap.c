/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:25:30 by jkeum             #+#    #+#             */
/*   Updated: 2021/03/12 23:14:32 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	set_mlx_bmp(t_vars *vars)
{
	if (!(vars->img = (t_img *)malloc(sizeof(t_img))))
		return (0);
	vars->img->img = mlx_new_image(vars->mlx, vars->scene->canvas.width,
			vars->scene->canvas.height);
	vars->img->addr = mlx_get_data_addr(vars->img->img,
			&vars->img->bits_per_pixel, &vars->img->line_length,
			&vars->img->endian);
	return (1);
}

static void	set_bitmap(t_vars *vars, int fd)
{
	int		tmp;
	char	bmp_file[14];
	char	bmp_info[40];

	ft_memset(&bmp_file, 0, 14);
	ft_memset(&bmp_info, 0, 40);
	ft_memmove(&bmp_file[0], "BM", 2);
	tmp = 54 + (vars->img->bits_per_pixel / 8) *
		vars->scene->canvas.width * vars->scene->canvas.height;
	ft_memmove(&bmp_file[2], &tmp, 4);
	tmp = 54;
	ft_memmove(&bmp_file[10], &tmp, 4);
	write(fd, bmp_file, 14);
	tmp = 40;
	ft_memmove(&bmp_info[0], &tmp, 4);
	ft_memmove(&bmp_info[4], &vars->scene->canvas.width, 4);
	tmp = -vars->scene->canvas.height;
	ft_memmove(&bmp_info[8], &tmp, 4);
	tmp = 1;
	ft_memmove(&bmp_info[12], &tmp, 2);
	ft_memmove(&bmp_info[14], &vars->img->bits_per_pixel, 2);
	tmp = (vars->img->bits_per_pixel / 8) *
		vars->scene->canvas.width * vars->scene->canvas.height;
	ft_memmove(&bmp_info[20], &tmp, 4);
	write(fd, bmp_info, 40);
}

static void	rendering_bmp(t_vars *vars)
{
	int		i;
	int		j;
	double	u;
	double	v;
	int		rgb;

	j = vars->scene->canvas.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < vars->scene->canvas.width)
		{
			u = (double)i / (vars->scene->canvas.width - 1);
			v = (double)j / (vars->scene->canvas.height - 1);
			vars->scene->ray = ray_primary(vars->scene->camera->element, u, v);
			rgb = create_rgb(ray_color(vars->scene));
			my_mlx_pixel_put(vars->img, vars->scene->canvas.width - i - 1,
					vars->scene->canvas.height - j - 1, rgb);
			i++;
		}
		j--;
	}
}

static int	save_bitmap(t_vars *vars)
{
	int				fd;
	int				i;
	int				j;
	unsigned int	*img;

	if ((fd = open("./image.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0666)) < 0)
		return (0);
	set_bitmap(vars, fd);
	rendering_bmp(vars);
	img = (unsigned int *)vars->img->addr;
	j = -1;
	while (++j < vars->scene->canvas.height)
	{
		i = -1;
		while (++i < vars->scene->canvas.width)
			write(fd, img + (j * vars->img->line_length / 4) + i,
					vars->img->bits_per_pixel / 8);
	}
	close(fd);
	return (1);
}

int			bitmap(char *argv, t_vars *vars)
{
	vars->mlx = mlx_init();
	mlx_get_screen_size(vars->mlx, &vars->scene->max_width,
			&vars->scene->max_height);
	if (!parse_rt(argv, vars->scene))
		return (0);
	if (!set_mlx_bmp(vars))
		return (-1);
	if (!save_bitmap(vars))
		return (0);
	return (1);
}
