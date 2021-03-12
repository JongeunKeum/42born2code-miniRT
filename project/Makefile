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
	   ./srcs/mlx_cntl/control/control.c	\
	   ./srcs/mlx_cntl/control/handle_keypress.c	\
	   ./srcs/parse/parse.c					\
	   ./srcs/parse/parse_utils.c			\
	   ./srcs/parse/parse_err.c				\
	   ./srcs/parse/parse_err_objs.c		\
	   ./srcs/parse/parse_info_racl.c		\
	   ./srcs/parse/parse_info_objs.c		\
	   ./srcs/scene/camera.c				\
	   ./srcs/scene/canvas.c				\
	   ./srcs/scene/ambient.c				\
	   ./srcs/scene/object_create.c			\
	   ./srcs/scene/create_objs.c			\
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
	   ./srcs/trace/trans/trans_utils.c		\
	   ./srcs/bitmap/bitmap.c				\
	   ./srcs/panel/print_panel.c			\
	   ./srcs/panel/object_panel.c			\
	   ./srcs/panel/selected_light.c		\
	   ./srcs/panel/default_object.c		\
	   ./srcs/panel/transform_panel.c		\
	   ./srcs/panel/axis_panel.c			\
	   ./srcs/panel/line_utils.c			\
	   ./srcs/utils/object_utils.c			\
	   ./srcs/utils/vec3_utils.c			\
	   ./srcs/utils/vec3_utils2.c			\
	   ./srcs/utils/constructors.c			\
	   ./srcs/utils/vec3_plus_minus.c		\
	   ./srcs/utils/vec3_mult_div.c			\
	   ./srcs/free/free_all.c

BONUS_SRCS = ./srcs/main.c 					\
	   ./srcs/gnl/get_next_line.c			\
	   ./srcs/gnl/get_next_line_utils.c		\
	   ./srcs/mlx_cntl/rendering.c			\
	   ./srcs/mlx_cntl/set_mlx.c			\
	   ./srcs/mlx_cntl/color.c				\
	   ./srcs/mlx_cntl/control/control.c	\
	   ./srcs/mlx_cntl/control/handle_keypress.c	\
	   ./srcs/parse/parse.c					\
	   ./srcs/parse/parse_utils.c			\
	   ./srcs/parse/parse_err.c				\
	   ./srcs/parse/parse_err_objs.c		\
	   ./srcs/parse/parse_info_racl.c		\
	   ./srcs/parse/parse_info_objs.c		\
	   ./srcs/scene/camera.c				\
	   ./srcs/scene/canvas.c				\
	   ./srcs/scene/ambient.c				\
	   ./srcs/scene/object_create.c			\
	   ./srcs/scene/create_objs.c			\
	   ./srcs/trace/hit/hit.c				\
	   ./srcs/trace/hit/normal.c			\
	   ./srcs/trace/hit/hit_cylinder.c		\
	   ./srcs/trace/hit/hit_plane.c			\
	   ./srcs/trace/hit/hit_sphere_rainbow.c	\
	   ./srcs/trace/hit/hit_triangle.c		\
	   ./srcs/trace/hit/hit_square.c		\
	   ./srcs/trace/ray/ray.c				\
	   ./srcs/trace/ray/phong_lighting.c	\
	   ./srcs/trace/trans/rotate.c			\
	   ./srcs/trace/trans/scale.c			\
	   ./srcs/trace/trans/translate.c		\
	   ./srcs/trace/trans/trans_utils.c		\
	   ./srcs/bitmap/bitmap.c				\
	   ./srcs/panel/print_panel.c			\
	   ./srcs/panel/object_panel.c			\
	   ./srcs/panel/selected_light.c		\
	   ./srcs/panel/default_object.c		\
	   ./srcs/panel/transform_panel.c		\
	   ./srcs/panel/axis_panel.c			\
	   ./srcs/panel/line_utils.c			\
	   ./srcs/utils/object_utils.c			\
	   ./srcs/utils/vec3_utils.c			\
	   ./srcs/utils/vec3_utils2.c			\
	   ./srcs/utils/constructors.c			\
	   ./srcs/utils/vec3_plus_minus.c		\
	   ./srcs/utils/vec3_mult_div.c			\
	   ./srcs/free/free_all.c

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
		   ./srcs/utils				\
		   ./srcs/free

OBJS_DIR = ./objs
OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))
BONUS_OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(BONUS_SRCS:.c=.o)))

LIBFT = libft.a
LIBFT_DIR = ./lib/libft
INC = ./includes
RM = rm -f

MLX = libmlx.dylib
#MLX_DIR = ./lib/mlx_linux
MLX_DIR = ./lib/mlx

vpath %.c $(SRCS_DIR)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx
	@install_name_tool -change $(MLX) $(MLX_DIR)/$(MLX) $(NAME)
#	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

bonus : $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) $(CFLAGS) -o $(NAME) $^ -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx
	@install_name_tool -change $(MLX) $(MLX_DIR)/$(MLX) $(NAME)

$(OBJS_DIR)/%.o : %.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -I$(INC) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $<

clean :
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean
	@$(RM) -r $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME) image.bmp

re : fclean all
