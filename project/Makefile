NAME = miniRT

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rc

SRCS = ./srcs/main.c 						\
	   ./srcs/gnl/get_next_line.c			\
	   ./srcs/gnl/get_next_line_utils.c		\
	   ./srcs/mlx_cntl/rendering.c			\
	   ./srcs/mlx_cntl/set_mlx.c			\
	   ./srcs/mlx_cntl/color.c				\
	   ./srcs/parse/parse.c					\
	   ./srcs/parse/parse_utils.c			\
	   ./srcs/scene/camera.c				\
	   ./srcs/scene/canvas.c				\
	   ./srcs/scene/object_create.c			\
	   ./srcs/trace/hit/hit.c				\
	   ./srcs/trace/hit/normal.c			\
	   ./srcs/trace/hit/hit_cylinder.c		\
	   ./srcs/trace/hit/hit_plane.c			\
	   ./srcs/trace/hit/hit_sphere.c		\
	   ./srcs/trace/hit/hit_triangle.c		\
	   ./srcs/trace/hit/hit_square.c		\
	   ./srcs/trace/ray/ray.c				\
	   ./srcs/trace/ray/phong_lighting.c	\
	   ./srcs/trace/trans/rotate.c			\
	   ./srcs/trace/trans/scale.c			\
	   ./srcs/trace/trans/translate.c		\
	   ./srcs/utils/object_utils.c			\
	   ./srcs/utils/vec3_utils.c
SRCS_DIR = ./srcs				\
		   ./srcs/gnl			\
		   ./srcs/mlx_cntl		\
		   ./srcs/parse			\
		   ./srcs/scene			\
		   ./srcs/trace/hit		\
		   ./srcs/trace/ray		\
		   ./srcs/trace/trans	\
		   ./srcs/utils

OBJS_DIR = ./objs
OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

LIBFT = libft.a
LIBFT_DIR = ./lib/libft
INC = ./includes
RM = rm -f

MLX = libmlx.dylib
MLX_DIR = ./lib/mlx

vpath %.c $(SRCS_DIR)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX_DIR)
#	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
#	@install_name_tool -change $(MLX) $(MLX_DIR)/$(MLX) $(NAME)

$(OBJS_DIR)/%.o : %.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAG) -o $@ -I$(INC) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $<

bonus : all

clean :
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean
	@$(RM) -r $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all
