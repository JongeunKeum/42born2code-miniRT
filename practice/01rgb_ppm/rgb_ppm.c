#include <stdio.h>

int	main(void)
{
	int		i;
	int		j;
	double	r;
	double	g;
	double	b;
	int		canvas_width;
	int		canvas_height;

	canvas_width = 256;
	canvas_height = 256;

	printf("P3\n%d %d\n255\n", canvas_width, canvas_height);
	/* P3 means the color value is ASCII code,
	   canvas columns and rows(pixels),
	   max color
	   */
	j = canvas_height;
	while (--j >= 0)
	{
		i = -1;
		while (++i < canvas_width)
		{
			r = (double)i / (canvas_width - 1);
			g = (double)j / (canvas_height - 1);
			b = 0.25;
			printf("%d %d %d\n", (int)(255.999 * r), (int)(255.999 * g), (int)(255.999 * b));
		}
	}
	return (0);
}
