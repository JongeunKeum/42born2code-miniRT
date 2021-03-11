#include "minirt.h"

void	top_bottom_panel(void)
{
	printf("+#:+#:+#:+#:");
	printf("+#:+#:+#:+#:");
	printf("+#:+#:+#:+#:");
	printf("+#:+#:+#:+#:");
	printf("\n");
}

void	next_previous_panel(int selected)
{
	printf("+----------------------------------------------+\n");
	printf("#   ");
	if (selected == OFF)
		printf("<-previous");
	else
		printf("%s<-previous", C_YLW);
	printf("%s\t\t\t      ", C_RESET);
	if (selected == OFF)
		printf("next->");
	else
		printf("%snext->", C_YLW);
	printf("%s   #\n", C_RESET);
	printf(":----------------------------------------------:\n");
}
