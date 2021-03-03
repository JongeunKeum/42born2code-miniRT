NAME = minirt

all : $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror -o $@ srcs/*.c srcs/*/*.c -I./includes

clean :
	rm $(NAME)

re :
	clean all
