# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 12:56:30 by ide-albe          #+#    #+#              #
#    Updated: 2023/04/24 18:19:26 by ide-albe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc -g
NAME		= so_long
MLX_LIB     = MLX42/libmlx42.a
LIBFTA		= libft/libft.a
CFLAGS		= -Wall -Wextra -Werror
LIBRARIES	= -lglfw -L "/Users/ide-albe/.brew/opt/glfw/lib" -lm -framework OpenGL
SRC			= so_long.c so_long_utils.c map.c map_errors.c map_errors_1.c map_utils.c player.c keyhooks.c wincondition.c
OBJ			= $(SRC:.c=.o)

all:		libft mlx $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(NAME):	mlx libft $(OBJ)
			$(CC) $(CFLAGS) $(LIBRARIES) $(OBJ) $(LIBFTA) $(MLX_LIB) -o $(NAME)
libft:
	make -C libft
mlx:
	make -C MLX42
clean:
	rm -rf $(OBJ)
	make -C libft clean

fclean:	
	rm -rf $(NAME)
	make -C libft fclean

re:

.PHONY:		mlx libft cd all clean fclean re