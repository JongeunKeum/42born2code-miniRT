MLX = libmlx.dylib
MLX_DIR = ./mlx
NAME = miniRT

all : ./mlx/libmlx.dylib
	gcc ./src/*.c ./src/*/*.c ./src/*/*/*.c -o $(NAME) -I./include -L./mlx -l mlx -I./mlx
	@install_name_tool -change $(MLX) $(MLX_DIR)/$(MLX) $(NAME)

clean :
	rm -rf $(NAME)
	rm -rf result.ppm

re : clean all

run : $(NAME)
	./$(NAME)

ppm : all
	./$(NAME) > result.ppm

./mlx/libmlx.dylib :
	make -c ./mlx

.PHONY : all clean re
