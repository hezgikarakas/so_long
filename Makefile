# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakaraka <hakaraka@student.42vienna.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 21:54:44 by hakaraka          #+#    #+#              #
#    Updated: 2023/08/24 12:45:08 by hakaraka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= 	so_long
CC				= 	cc
CFLAGS			= 	-Wall -Wextra -Werror -Iincludes -Ilibft

SRCS			=	src/main.c src/ft_free_funcs.c src/ft_init_map.c \
				src/ft_gnl.c src/ft_check_map.c src/ft_init_game.c \
				src/ft_render.c src/ft_close_game.c src/ft_mouse_moves.c \
				src/ft_flood_fill.c  src/ft_utils.c

OBJS 			=	$(SRCS:%.c=%.o)

LDFLAGS			= 	-lXext -lX11 -lmlx

LIBFT_LIB		=	./libft/libft.a

RM				=	rm -rf

all				: 	$(NAME)

$(OBJS)			:	$(SRCS)
					$(CC) $(CFLAGS) -c $?
					@mv *.o src

$(NAME)			: 	$(OBJS)
					@make -C libft
					$(CC) -o $@ $(OBJS) $(LDFLAGS) $(CFLAGS) $(LIBFT_LIB)

clean 			:
					$(RM) src/*.o
					make clean -C libft

fclean 			:	clean
					make fclean -C libft
					$(RM) $(NAME)

.PHONY			:	all clean fclean re

re				:	fclean all
					$(RM) src/*.o
