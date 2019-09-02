# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchocho <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 09:51:23 by mchocho           #+#    #+#              #
#    Updated: 2019/09/02 15:55:00 by mchocho          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:=	ft_ls.a

HEADERS:=	ft_ls.h

FLAGS:=	-Wall -Werror -Wextra

SRC:=	ft_addhead.c\
	ft_addtail.c\
	ft_constructctimeobj.c\
	ft_detectfiletype.c\
	ft_detectfilepathtype.c\
	ft_filecount.c\
	ft_hardlinkcount.c\
	ft_ispathdir.c\
	ft_initlist.c\
	ft_initflagobject.c\
	ft_ispathdir.c\
	ft_isvalidoption.c\
	ft_longlist.c\
	ft_ls.c\
	ft_printdatetime.c\
	ft_printgroupname.c\
	ft_printlist.c\
	ft_printoptions.c\
	ft_printpermissions.c\
	ft_printusername.c\
	ft_reverselist.c\
	ft_scanfile.c\
	ft_sortbyascii.c\
	ft_sortbytime.c\
	ft_sortlist.c\
	ft_splicepath.c\
	ft_structcmp.c\
	ft_totalsize.c\
	ft_verifyflag.c

OBJECTS:= $(SRC:.c=.o)

$(NAME):
	gcc $(FLAGS) $(SRC) $(HEADERS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
	rm libft.h.gch

all:	$(NAME)
	
clean:
	rm -f $(OBJECTS)
	rm -f libft.h.gch

fclean:	clean
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
