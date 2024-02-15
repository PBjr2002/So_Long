CC = cc
CFLAGS = -g -Wall -Wextra -Werror
NAME = so_long

SRC = $(addprefix src/, $(SOURCES))
SOURCES = so_long.c check_map.c check_map2.c flood_fill.c map_utils.c load_map.c load_player.c\
			load_transparency.c load_layer2.c free_imgs.c movement.c load_frame.c error.c\
			create_player_map.c

OBJS_DIR = obj
OBJECTS = $(addprefix $(OBJS_DIR)/, $(SRC:src/%.c=%.o))

MLX_DIR = ./mlx/
MLX = $(MLX_DIR)libmlx.a -lXext -lX11 -lm -lz

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a

all: $(NAME)

$(NAME): $(OBJECTS) $(MLX) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(MLX) $(LIBFT)

$(OBJS_DIR)/%.o: src/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX): 
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
		$(MAKE) clean -C $(LIBFT_DIR)
		$(MAKE) clean -C $(MLX_DIR)
		rm -rf $(OBJS_DIR)

fclean: clean
		$(MAKE) fclean -C $(LIBFT_DIR)
		$(MAKE) clean -C $(MLX_DIR)
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re