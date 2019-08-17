# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchocho <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 09:51:23 by mchocho           #+#    #+#              #
#    Updated: 2019/08/16 21:58:10 by mchocho          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	ft_ls.a

HEADERS=	ft_ls.h

FLAGS=	-Wall -Werror -Wextra

SRC=	./ft_ls.c\
		./ft_longlist.c\
		./ft_filecount.c\
		./ft_detectfiletype.c\
		./ft_detectfilepathtype.c\
		./ft_ispathdir.c\
		./ft_printdatetime.c\
		./ft_printpermissions.c\
		./ft_printgroupname.c\
		./ft_printusername.c\
		./ft_totalblocks.c\
		./ft_totalsize.c\
		./ft_splicepath.c\
		./libft/ft_putchar.c\
		./libft/ft_putstr.c

OBJECTS: $(SRC:.c=.o)

$(NAME):
	gcc $(FLAGS) $(SRC) $(HEADERS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
	rm libft.h.gch

all:	$(NAME)
	
clean:	rm -f $(OBJECTS)
		rm libft.h.gch

clean:
	rm -f $(OBJECTS)

fclean:	clean
		rm -f $(NAME)

norm:
	norminette $(FN)

compile:
	gcc $(FLAGS) $(FN)

out:
	./a.out

outw:
	./a.exe

.PHONY: re, clean, fclean, all
