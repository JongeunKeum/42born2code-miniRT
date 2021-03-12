#include "libft.h"

double	ft_atod(char *str)
{
	double	result;
	int		sign;
	int		ten;

	result = 0.0;
	sign = 1;
	ten = 10;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + (*str++ - '0');
	if (*str++ == '.')
		while (*str >= '0' && *str <= '9')
		{
			result += (double)(*str++ - '0') / ten;
			ten *= 10;
		}
	return ((double)(result * sign));
}
