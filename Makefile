# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 19:30:44 by ykruhlyk          #+#    #+#              #
#    Updated: 2022/05/25 19:48:55 by ykruhlyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_print_csd.c ft_print_u.c ft_print_ptr.c ft_print_hex.c ft_libft.c\

OBJ =  $(SRC:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
all :$(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)
				
clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re 