CFLAGS = -Wall -Wextra -Werror
CC = cc
NAME = cub3D

SRC =  main.c parsing/get_next_line.c parsing/get_next_line_utils.c parsing/parse_first_part.c\
  	   parsing/additional_functions1.c parsing/additional_functios.c parsing/additional_functions_2.c \
	   parsing/additional_functions_3.c parsing/additional_functions_4.c parsing/pars.c\
	   parsing/pars2.c parsing/pars3.c parsing/pars4.c parsing/pars5.c parsing/init.c game_loop/free_elements.c game_loop/initialization.c game_loop/keys_manager.c  \
	   game_loop/texturespart.c game_loop/tools.c game_loop/world_maker.c game_loop/start_game.c game_loop/movement.c game_loop/ray_casting.c
		

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





