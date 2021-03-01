#include "minirt.h"

void	configuration(char **split)
{
	int	i;

	i = -1;
	while (split[0][++i])
		split[0][i] = ft_toupper(split[0][i]);
	if (ft_strlen(split[0]) == 1)
	{
		if (ft_strncmp(split[0], "R", 1))
			printf("object:\t%s", split[0]);
		else if (ft_strncmp(split[0], "A", 1))
			printf("object:\t%s", split[0]);
		else if (ft_strncmp(split[0], "C", 1))
			printf("object:\t%s", split[0]);
		else if (ft_strncmp(split[0], "L", 1))
			printf("object:\t%s", split[0]);
	}
}

void	set_object(char **split)
{
	int	i;

	i = -1;
	while (split[0][++i])
		split[0][i] = ft_toupper(split[0][i]);
	if (ft_strlen(split[0]) == 2)
	{
		if (ft_strncmp(split[0], "PL", 2))
			printf("object:\t%s", split[0]);
		else if (ft_strncmp(split[0], "SP", 2))
			printf("object:\t%s", split[0]);
		else if (ft_strncmp(split[0], "SQ", 2))
			printf("object:\t%s", split[0]);
		else if (ft_strncmp(split[0], "CY", 2))
			printf("object:\t%s", split[0]);
		else if (ft_strncmp(split[0], "TR", 2))
			printf("object:\t%s", split[0]);
	}
}

void	parsing(char *str)
{
    char	*line;
    int		n;
    int		fd;
	char	**split;
	int		i;

	line = 0;
    fd = open(str, O_RDONLY);
    while ((n = get_next_line(fd, &line)) > 0)
    {
		split = ft_split(line, ' ');
		set_object(split);
		printf("\n");
        free(line);
    }
}

int		main(int argc, char *argv[])
{
	parsing(argv[1]);
	return (0);
}
