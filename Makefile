# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 00:40:38 by macarval          #+#    #+#              #
#    Updated: 2023/12/29 12:30:59 by macarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE_PATH	= src/

FILE_PATH_BONUS	= src_bonus/

FILE		= colors.c events.c fractol.c images.c  \
			libft.c rendering.c models.c window.c

FILE_BONUS	= colors_bonus.c events_bonus.c fractol_bonus.c \
 			images_bonus.c libft_bonus.c rendering_bonus.c \
			models_bonus.c window_bonus.c

FILES		= $(addprefix $(FILE_PATH), $(FILE))

FILES_BONUS	= $(addprefix $(FILE_PATH_BONUS), $(FILE_BONUS))

EXE			= $(FILES:.c=.o)

EXE_BONUS	= $(FILES_BONUS:.c=.o)

NAME		= fractol

GCC			= cc

CFLAGS		= -Wall -Wextra -Werror

LFLAGS		= -lmlx -Ilmlx -lXext -lX11 -O3

all:		$(NAME)

.c.o:
			$(GCC) -c $< -I. -o $(<:.c=.o) $(CFLAGS)

bonus:		$(EXE_BONUS)
			$(GCC) $(CFLAGS) $(EXE_BONUS) $(LFLAGS) -I. -o $(NAME)

$(NAME):	$(EXE)
			$(GCC) $(CFLAGS) $(EXE) $(LFLAGS) -I. -o $(NAME)

clean:
			rm -f $(EXE) $(EXE_BONUS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: all bonus clean fclean re
