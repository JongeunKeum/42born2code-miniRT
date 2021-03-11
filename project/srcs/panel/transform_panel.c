/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_panel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:37:55 by jkeum             #+#    #+#             */
/*   Updated: 2021/03/11 18:37:56 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	selected_translate(void)
{
	printf("+\t\t\t\t\t       +\n");
	printf("#   %s        %s\t\t\t\t       #\n", B_BLUE, B_RESET);
	printf(":   %s  %s    %s  %s\t       %s   %s\t       %s   %s     :\n", B_BLUE, B_WHT, B_BLUE, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET);
	printf("+   %s   %s  %s   %s\t       %s %s  %s %s\t      %s %s%s  %s      +\n", B_BLUE, B_WHT, B_BLUE, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET, U_WHT, B_RESET); 
	printf("#   %s   %s  %s   %s\t       %s   %s\t         %s %s     #\n", B_BLUE, B_WHT, B_BLUE, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET);
	printf(":   %s   %s  %s   %s\t       %s %s  %s %s\t      %s   %s      :\n", B_BLUE, B_WHT, B_BLUE, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET);
	printf("+   %s        %s\t\t\t\t       +\n", B_BLUE, B_RESET);
	printf("#\t\t\t\t\t       #\n");
	printf(":----------------------------------------------:\n");
}

void	selected_rotate(void)
{
	printf("+\t\t\t\t\t       +\n");
	printf("#\t\t     %s        %s\t\t       #\n", B_BLUE, B_RESET);
	printf(":     %s    %s\t     %s  %s   %s   %s\t       %s   %s     :\n", B_WHT, B_RESET, B_BLUE, B_WHT, B_BLUE, B_RESET, B_WHT, B_RESET);
	printf("+      %s  %s\t     %s  %s %s  %s %s  %s\t      %s %s%s  %s      +\n", B_WHT, B_RESET, B_BLUE, B_WHT, B_BLUE, B_WHT, B_BLUE, B_RESET, B_WHT, B_RESET, U_WHT, B_RESET);
	printf("#      %s  %s\t     %s  %s   %s   %s\t         %s %s     #\n", B_WHT, B_RESET, B_BLUE, B_WHT, B_BLUE, B_RESET, B_WHT, B_RESET);
	printf(":      %s  %s\t     %s  %s %s  %s %s  %s\t      %s   %s      :\n", B_WHT, B_RESET, B_BLUE, B_WHT, B_BLUE, B_WHT, B_BLUE, B_RESET, B_WHT, B_RESET);
	printf("+\t\t     %s        %s\t\t       +\n", B_BLUE, B_RESET);
	printf("#\t\t\t\t\t       #\n");
	printf(":----------------------------------------------:\n");
}

void	selected_scale(void)
{
	printf("+\t\t\t\t\t       +\n");
	printf("#\t\t\t\t    %s        %s   #\n", B_BLUE, B_RESET);
	printf(":     %s    %s\t       %s   %s\t    %s   %s   %s  %s   :\n", B_WHT, B_RESET, B_WHT, B_RESET, B_BLUE, B_WHT, B_BLUE, B_RESET);
	printf("+      %s  %s\t       %s %s  %s %s\t    %s  %s %s%s  %s   %s   +\n", B_WHT, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET, B_BLUE, B_WHT, B_BLUE, U_WHT, B_BLUE, B_RESET);
	printf("#      %s  %s\t       %s   %s\t    %s     %s %s  %s   #\n", B_WHT, B_RESET, B_WHT, B_RESET, B_BLUE, B_WHT, B_BLUE, B_RESET);
	printf(":      %s  %s\t       %s %s  %s %s\t    %s  %s   %s   %s   :\n", B_WHT, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET, B_BLUE, B_WHT, B_BLUE, B_RESET);
	printf("+\t\t\t\t    %s        %s   +\n", B_BLUE, B_RESET);
	printf("#\t\t\t\t\t       #\n");
	printf(":----------------------------------------------:\n");
}

void	default_transform(void)
{
	printf("+\t\t\t\t\t       +\n");
	printf("#\t\t\t\t\t       #\n");
	printf(":     %s    %s\t       %s   %s   \t       %s   %s     :\n", B_WHT, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET);
	printf("+      %s  %s\t       %s %s  %s %s  \t      %s %s%s  %s      +\n", B_WHT, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET, U_WHT, B_RESET);
	printf("#      %s  %s\t       %s   %s   \t         %s %s     #\n", B_WHT, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET);
	printf(":      %s  %s\t       %s %s  %s %s  \t      %s   %s      :\n", B_WHT, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET);
	printf("+\t\t\t\t\t       +\n");
	printf("#\t\t\t\t\t       #\n");
	printf(":----------------------------------------------:\n");
}

void	transform_panel(int trans)
{
	if (trans == TRANSLATE)
		selected_translate();
	else if (trans == ROTATE)
		selected_rotate();
	else if (trans == SCALE)
		selected_scale();
	else if (trans == OFF)
		default_transform();
}
