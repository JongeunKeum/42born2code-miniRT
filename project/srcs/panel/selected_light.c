#include <stdio.h>
#define B_YLW "\e[0;103m"
#define B_WHT "\e[47m"
#define B_RESET "\e[0m"

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
