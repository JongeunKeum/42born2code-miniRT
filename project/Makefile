NAME = miniRT
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rc
SRCS = ./srcs/main.c
SRCS_DIR = ./srcs
OBJS = $(SRCS:.c=.o)
OBJS_DIR = ./objs
LIBFT = libft.a
LIBFT_DIR = ./lib/libft
INC = ./includes
RM = rm -f
MLX = libmlx.dylib
MLX_DIR = ./lib/mlx

all : $(NAME)

$(NAME) : $(addprefix $(OBJS_DIR)/, $(OBJS))
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx
	@install_name_tool -change $(MLX) $(MLX_DIR)/$(MLX) $(NAME)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
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
