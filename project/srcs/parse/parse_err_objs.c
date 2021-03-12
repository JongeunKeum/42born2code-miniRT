/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_err_objs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 00:52:27 by jkeum             #+#    #+#             */
/*   Updated: 2021/03/13 00:52:29 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_err_sp(char **info)
{
	if (count_info(info) != 4)
		return (0);
	if (ft_atoi(info[2]) < 0)
		return (0);
	return (1);
}

int	check_err_pl(char **info)
{
	if (count_info(info) != 4)
		return (0);
	return (1);
}

int	check_err_sq(char **info)
{
	if (count_info(info) != 5)
		return (0);
	if (ft_atoi(info[3]) < 0)
		return (0);
	return (1);
}

int	check_err_cy(char **info)
{
	if (count_info(info) != 6)
		return (0);
	if (ft_atoi(info[3]) < 0 || ft_atoi(info[4]) < 0)
		return (0);
	return (1);
}

int	check_err_tr(char **info)
{
	if (count_info(info) != 5)
		return (0);
	return (1);
}
