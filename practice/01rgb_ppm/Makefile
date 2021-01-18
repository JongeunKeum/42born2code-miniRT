NAME = minirt

all :
	gcc *.c -o $(NAME)

clean :
	rm -rf $(NAME)
	rm -rf result.ppm

re : clean all

run : $(NAME)
	./$(NAME)

ppm : $(NAME)
	./$(NAME) > result.ppm

.PHONY : all clean re
