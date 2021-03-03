/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:44:45 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/02 17:57:51 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_isright_info(char c)
{
	return (ft_isdigit(c) || ft_issign(c) || c == ',' || c == '.');
}

int	check_info_err(char **info)
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
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}
