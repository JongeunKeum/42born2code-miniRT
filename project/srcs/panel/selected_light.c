/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selected_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:38:06 by jkeum             #+#    #+#             */
/*   Updated: 2021/03/11 18:38:07 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	line_one_three(void)
{
	printf("#\t\t\t\t\t       #\n");
	printf(":   ");
	printf("%s        ", B_YLW);
	printf("%s                                ", B_RESET);
	printf("   :\n+   ");
	printf("%s  ", B_YLW);
	printf("%s ", B_WHT);
	printf("%s     ", B_YLW);
	printf("%s           ", B_RESET);
	printf("%s   ", B_WHT);
	printf("%s             ", B_RESET);
	printf("%s  ", B_WHT);
	printf("%s      +\n#   ", B_RESET);
	printf("%s  ", B_YLW);
	printf("%s ", B_WHT);
	printf("%s     ", B_YLW);
	printf("%s          ", B_RESET);
	printf("%s ", B_WHT);
	printf("%s               ", B_RESET);
	printf("%s ", B_WHT);
	printf("%s  ", B_RESET);
	printf("%s ", B_WHT);
	printf("%s     #\n", B_RESET);
}

static void	line_four_six(void)
{
	printf(":   ");
	printf("%s  ", B_YLW);
	printf("%s ", B_WHT);
	printf("%s     ", B_YLW);
	printf("%s          ", B_RESET);
	printf("%s ", B_WHT);
	printf("%s               ", B_RESET);
	printf("%s ", B_WHT);
	printf("%s  ", B_RESET);
	printf("%s ", B_WHT);
	printf("%s     :\n+   ", B_RESET);
	printf("%s  ", B_YLW);
	printf("%s    ", B_WHT);
	printf("%s  ", B_YLW);
	printf("%s           ", B_RESET);
	printf("%s   ", B_WHT);
	printf("%s             ", B_RESET);
	printf("%s  ", B_WHT);
	printf("%s      +\n", B_RESET);
	printf("#   ");
	printf("%s        ", B_YLW);
	printf("%s                                ", B_RESET);
	printf("   #\n");
	printf(":\t\t\t\t\t       :\n");
}

void	selected_light(void)
{
	line_one_three();
	line_four_six();
}
