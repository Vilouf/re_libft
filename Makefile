# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vielblin <vielblin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 12:08:07 by vielblin          #+#    #+#              #
#    Updated: 2024/10/14 12:15:33 by vielblin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =

OBJ = $(SRC.c=.o)

all: $(NAME)

$(NAME):
	cc -Wall -Wextra -Werror $(SRC)
	ar rc $(NAME) $(OBJ)
	rablib $(NAME)

clean:
	rm $(OBJ)

fclean:
	rm $(OBJ)
	rn $(NAME)

re: fclean all
