# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: magoumi <agoumihunter@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/04 22:41:07 by magoumi           #+#    #+#              #
#    Updated: 2018/11/04 20:18:47 by magoumi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = $(wildcard *.c)
NAME = libft.a
all: $(NAME)
$(NAME):
	gcc -c $(SRC) -Werror -Wall -Wextra
	ar rc $(NAME) *.o
clean :
	rm -f $(wildcard *.o)
fclean : clean
	rm -rf $(NAME)
re : fclean all
