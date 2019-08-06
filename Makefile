# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchocho <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 09:51:23 by mchocho           #+#    #+#              #
#    Updated: 2019/07/23 11:09:17 by mchocho          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME: ft_ls.a

HEADERS: ft_ls.h

FLAGS: -Wall -Werror -Wextra

SRC = ./ft_listdir.c\
      ./ft_detectfiletype.c\
      ./ft_filecount.c\
      ./ft_ispathdir.c\
      ./ft_longlist.c\
      ./ft_printpermissions.c\
      ./ft_printusername.c\
      ./ft_totalblocks.c\
      ./ft_totalsize.c

OBJECTS = $(SRC:.c=.o)

all: $(NAME)                                                                                                                                                                                      

$(NAME): gcc $(FLAGS) $(SRC) $(HEADERS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
	rm libft.h.gch
	
clean: 	rm -f $(OBJECTS)
	rm libft.h.gch

fclean:
	clean
	rm -f $(NAME)

re:	fclean all

norm:
	norminette $(FN)

compile:
	gcc $(FLAGS) $(FN)

out:
	./a.out

outw:
	./a.exe

.PHONY: re, clean, fclean, all
