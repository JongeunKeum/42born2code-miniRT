/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_panel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:38:02 by jkeum             #+#    #+#             */
/*   Updated: 2021/03/11 18:38:03 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	selected_camera(void)
{
	printf("#\t\t\t\t\t       #\n");
	printf(":\t\t     %s        %s                  :\n", B_YLW, B_RESET);
	printf("+      %s %s             %s   %s   %s  %s          %s  %s      +\n", B_WHT, B_RESET, B_YLW, B_WHT, B_YLW, B_RESET, B_WHT, B_RESET);
	printf("#      %s %s             %s  %s %s     %s         %s %s  %s %s     #\n", B_WHT, B_RESET, B_YLW, B_WHT, B_YLW, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET);
	printf(":      %s %s             %s  %s %s     %s         %s %s  %s %s     :\n", B_WHT, B_RESET, B_YLW, B_WHT, B_YLW, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET);
	printf("+      %s    %s          %s   %s   %s  %s          %s  %s      +\n", B_WHT, B_RESET, B_YLW, B_WHT, B_YLW, B_RESET, B_WHT, B_RESET);
	printf("#\t\t     %s        %s                  #\n", B_YLW, B_RESET);
	printf(":\t\t\t\t\t       :\n");
}

void	selected_object(void)
{
	printf("#\t\t\t\t\t       #\n");
	printf(":\t\t\t\t    %s        %s   :\n", B_YLW, B_RESET);
	printf("+     %s %s\t\t       %s   %s\t    %s   %s  %s   %s   +\n", B_WHT, B_RESET, B_WHT, B_RESET, B_YLW, B_WHT, B_YLW, B_RESET);
	printf("#     %s %s\t\t      %s %s\t\t    %s  %s %s  %s %s  %s   #\n", B_WHT, B_RESET, B_WHT, B_RESET, B_YLW, B_WHT, B_YLW, B_WHT, B_YLW, B_RESET);
	printf(":     %s %s\t\t      %s %s\t\t    %s  %s %s  %s %s  %s   :\n", B_WHT, B_RESET, B_WHT, B_RESET, B_YLW, B_WHT, B_YLW, B_WHT, B_YLW, B_RESET);
	printf("+     %s    %s\t       %s   %s\t    %s   %s  %s   %s   +\n", B_WHT, B_RESET, B_WHT, B_RESET, B_YLW, B_WHT, B_YLW, B_RESET);
	printf("#\t\t\t\t    %s        %s   #\n", B_YLW, B_RESET);
	printf(":\t\t\t\t\t       :\n");
}

void	object_panel(int selected)
{
	if (selected == OFF)
		default_object();
	else if (selected == LIGHT_POINT)
		selected_light();
	else if (selected == CAM)
		selected_camera();
	else if (selected == OBJECT)
		selected_object();
}
