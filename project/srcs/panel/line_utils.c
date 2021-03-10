#include <stdio.h>
#define C_YLW "\e[0;33m"
#define C_RESET "\e[0m"

void	top_bottom_panel(void)
{
	printf("+#:+#:+#:+#:");
	printf("+#:+#:+#:+#:");
	printf("+#:+#:+#:+#:");
	printf("+#:+#:+#:+#:");
	printf("\n");
}

void	next_previous_panel(void)
{
	printf("+----------------------------------------------+\n");
	printf("#   ");
	printf("%s<-previous", C_YLW);
	printf("%s\t\t\t      ", C_RESET);
	printf("%snext->", C_YLW);
	printf("%s   #\n", C_RESET);
	printf(":----------------------------------------------:\n");
}
