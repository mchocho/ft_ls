# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchocho <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 09:51:23 by mchocho           #+#    #+#              #
#    Updated: 2019/08/03 15:30:52 by mchocho          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME: ft_ls.a

HEADERS: ft_ls.h

FLAGS: -Wall -Werror -Wextra -o

SRC: 	./ft_listdir.c\
		./ft_longlist.c\
		./ft_filecount.c\
		./detectfiletype.c\
		./ispathdir.c\
		./ft_printdatetime.c\
		./ft_printpermissions.c\
		./ft_printgroupname.c\
		./ft_printusername.c\
		./totalblocks.c\
		./ft_totalsize.c

OBJECTS: $(SRC:.c=.o)

$(NAME):
	gcc $(FLAGS) $(SRC) $(HEADERS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all

compile:
	gcc $(FLAGS) $(FN)

out:
	./a.out

outw:
	./a.exe

.PHONY: re, clean, fclean, all
