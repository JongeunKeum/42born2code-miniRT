#include <stdio.h>

void	default_object(void);
void	selected_light(void);
void	selected_camera(void);
void	top_bottom_panel(void);
void	next_previous_panel(void);

void	object_panel(void)
{
	top_bottom_panel();
	selected_light();
	next_previous_panel();
	printf("\n\n");
//	default_object();
	selected_camera();
}
