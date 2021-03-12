NAME = miniRT

CC = gcc
# CFLAGS = -g3 -fsanitize=address #-Wall -Wextra -Werror
AR = ar
ARFLAGS = rc

SRCS = ./srcs/main.c 						\
	   ./srcs/gnl/get_next_line.c			\
	   ./srcs/gnl/get_next_line_utils.c		\
	   ./srcs/mlx_cntl/rendering.c			\
	   ./srcs/mlx_cntl/set_mlx.c			\
	   ./srcs/mlx_cntl/color.c				\
	   ./srcs/mlx_cntl/control/control.c	\
	   ./srcs/parse/parse.c					\
	   ./srcs/parse/parse_utils.c			\
	   ./srcs/parse/parse_err.c				\
	   ./srcs/scene/camera.c				\
	   ./srcs/scene/canvas.c				\
	   ./srcs/scene/ambient.c				\
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
	   ./srcs/bitmap/bitmap.c				\
	   ./srcs/panel/print_panel.c			\
	   ./srcs/panel/object_panel.c			\
	   ./srcs/panel/selected_light.c		\
	   ./srcs/panel/default_object.c		\
	   ./srcs/panel/transform_panel.c		\
	   ./srcs/panel/axis_panel.c			\
	   ./srcs/panel/line_utils.c			\
	   ./srcs/utils/object_utils.c			\
	   ./srcs/utils/vec3_utils.c
SRCS_DIR = ./srcs					\
		   ./srcs/gnl				\
		   ./srcs/mlx_cntl			\
		   ./srcs/mlx_cntl/control	\
		   ./srcs/parse				\
		   ./srcs/scene				\
		   ./srcs/trace/hit			\
		   ./srcs/trace/ray			\
		   ./srcs/trace/trans		\
		   ./srcs/bitmap			\
		   ./srcs/panel				\
		   ./srcs/utils

OBJS_DIR = ./objs
OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

LIBFT = libft.a
LIBFT_DIR = ./lib/libft
INC = ./includes
RM = rm -f

MLX = libmlx.dylib
MLX_DIR = ./lib/mlx_linux
MLX_MAC_DIR = ./lib/mlx

vpath %.c $(SRCS_DIR)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
#	@$(MAKE) -C $(MLX_DIR)
	@$(MAKE) -C $(MLX_MAC_DIR)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft -L$(MLX_MAC_DIR) -lmlx
	@install_name_tool -change $(MLX) $(MLX_MAC_DIR)/$(MLX) $(NAME)
#	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

$(OBJS_DIR)/%.o : %.c
	@mkdir -p $(OBJS_DIR)
#	@$(CC) $(CFLAGS) -o $@ -I$(INC) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $<
	@$(CC) $(CFLAGS) -o $@ -I$(INC) -I$(LIBFT_DIR) -I$(MLX_MAC_DIR) -c $<

bonus : all

clean :
	@$(MAKE) -C $(LIBFT_DIR) fclean
#	@$(MAKE) -C $(MLX_DIR) clean
	@$(MAKE) -C $(MLX_MAC_DIR) clean
	@$(RM) -r $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all
