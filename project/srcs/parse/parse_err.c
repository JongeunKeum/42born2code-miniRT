/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:44:13 by jkeum             #+#    #+#             */
/*   Updated: 2021/03/11 18:44:20 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	count_info(char **info)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (info[i++])
		cnt++;
	return (cnt);
}

int			check_err_r(char **info)
{
	if (count_info(info) != 3)
		return (0);
	if (ft_atoi(info[1]) < 0 || ft_atoi(info[2]) < 0)
		return (0);
	return (1);
}

int			check_err_a(char **info)
{
	if (count_info(info) != 3)
		return (0);
	if (ft_atoi(info[1]) < 0 || ft_atoi(info[1]) > 1)
		return (0);
	return (1);
}

int			check_err_c(char **info)
{
	if (count_info(info) != 4)
		return (0);
	if (ft_atoi(info[3]) <= 0 || ft_atoi(info[3]) > 180)
		return (0);
	return (1);
}

int			check_err_l(char **info)
{
	if (count_info(info) != 4)
		return (0);
	if (ft_atoi(info[2]) < 0 || ft_atoi(info[2]) > 1)
		return (0);
	return (1);
}

int			check_err_sp(char **info)
{
	if (count_info(info) != 4)
		return (0);
	if (ft_atoi(info[2]) < 0)
		return (0);
	return (1);
}

int			check_err_pl(char **info)
{
	if (count_info(info) != 4)
		return (0);
	return (1);
}

int			check_err_sq(char **info)
{
	if (count_info(info) != 5)
		return (0);
	if (ft_atoi(info[3]) < 0)
		return (0);
	return (1);
}

int			check_err_cy(char **info)
{
	if (count_info(info) != 6)
		return (0);
	if (ft_atoi(info[3]) < 0 || ft_atoi(info[4]) < 0)
		return (0);
	return (1);
}

int			check_err_tr(char **info)
{
	if (count_info(info) != 5)
		return (0);
	return (1);
}
