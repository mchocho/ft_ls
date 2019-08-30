# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchocho <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 09:51:23 by mchocho           #+#    #+#              #
#    Updated: 2019/08/30 14:59:06 by mchocho          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	ft_ls.a

HEADERS	:=	ft_ls.h

FLAGS	:=	-Wall -Werror -Wextra

SRC :=	ft_addhead.c\
	ft_addtail.c\
	ft_constructctimeobj.c\
	ft_detectfiletype.c\
	ft_detectfilepathtype.c\
	ft_filecount.c\
	ft_ispathdir.c\
	ft_inithead.c\
	ft_initflagobject.c\
	ft_longlist.c\
	ft_ls.c\
	ft_printdatetime.c\
	ft_printfiles_r.c\
	ft_printfile_t.c\
	ft_printgroupname.c\
	ft_printpermissions.c\
	ft_printusername.c\
	ft_reverselist.c\
	ft_scanfile.c\
	ft_sortbyascii.c\
	ft_sortbytime.c\
	ft_sortlist.c\
	ft_splicepath.c\
	ft_totalblocks.c\
	ft_totalsize.c\

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
