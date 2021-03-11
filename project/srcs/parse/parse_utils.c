/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:44:26 by jkeum             #+#    #+#             */
/*   Updated: 2021/03/11 18:45:11 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	ft_isright_info(char c)
{
	return (ft_isdigit(c) || ft_issign(c) || c == ',' || c == '.');
}

int			check_color(t_color3 color)
{
	if (color.x < 0 || color.y < 0 || color.z < 0)
		return (0);
	return (1);
}

int			check_info_err(char **info)
{
	int	i;
	int	j;

	i = 1;
	while (info[i])
	{
		j = 0;
		while (info[i][j])
		{
			if (!(ft_isright_info(info[i][j])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
