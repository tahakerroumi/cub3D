CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
CC = cc
NAME = cub3D

SRC = main.c \
		parsing/additional_functions.c parsing/additional_functions2.c parsing/additional_functions3.c \
		parsing/check_elements.c parsing/check_elements2.c parsing/check_extention.c parsing/fill_file.c \
		parsing/ft_split.c parsing/get_next_line_utils.c parsing/get_next_line.c parsing/mapsize.c \
		parsing/pars.c parsing/playerexists.c \
		game_loop/initialization.c game_loop/keys_manager.c game_loop/ray_casting.c game_loop/start_game.c \
		game_loop/texturespart.c game_loop/tools.c game_loop/world_maker.c
		

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all