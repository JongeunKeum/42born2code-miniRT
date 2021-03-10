#include <stdio.h>
#define B_WHT "\e[47m"
#define B_YLW "\e[0;103m"
#define B_RESET "\e[0m"

static void	line_one_three(void)
{
	printf("#\t\t\t\t\t       #\n:\t\t    ");
	printf("%s        ", B_YLW);
	printf("%s\t\t       :\n", B_RESET);
}

void	selected_camera(void)
{
	line_one_three();
//	line_four_six();
}
