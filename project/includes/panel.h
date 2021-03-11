#ifndef PANEL_H
# define PANEL_H

# define B_YLW "\e[0;103m"
# define B_WHT "\e[47m"
# define B_RESET "\e[0m"
# define B_BLUE "\e[0;104m"
# define U_WHT "\e[4;37m"
# define B_PRPL "\e[0;105m"

void	top_bottom_panel();
void	selected_light(void);
void	default_object(void);
void	object_panel(int selected);
void	next_previous_panel(int selected);
void	transform_panel(int trans);
void	axis_panel(int axis);

#endif
