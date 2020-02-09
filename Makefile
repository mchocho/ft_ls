# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchocho <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 09:51:23 by mchocho           #+#    #+#              #
#    Updated: 2020/02/09 11:37:50 by mchocho          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:=	ft_ls.a

HEADERS:= ./includes/ft_ls.h

FLAGS:=	-Wall -Werror -Wextra -c

SRC:=	./src/ft_addtail.c\
	./src/ft_cleanlist.c\
	./src/ft_destroyflagship.c\
	./src/ft_filecount.c\
	./src/ft_filetype.c\
	./src/ft_initlist.c\
	./src/ft_initflagobject.c\
	./src/ft_isvalidoption.c\
	./src/ft_longlist.c\
	./src/ft_ls.c\
	./src/ft_parseurl.c\
	./src/ft_printlist.c\
	./src/ft_printoptions.c\
	./src/ft_reverselist.c\
	./src/ft_scanfile.c\
	./src/ft_sortbyascii.c\
	./src/ft_sortbytime.c\
	./src/ft_sortlist.c\
	./src/ft_splicepath.c\
	./src/ft_structcmp.c\
	./src/ft_isdrl.c\
	./src/ft_assembleflagship.c\
	./src/ft_errormessage.c

TEMP = $(subst /src/,/includes/,$(SRC))
OBJECTS = $(TEMP:.c=.o)
LIBFT:=	./libft/

$(NAME):
	$(MAKE) -C $(LIBFT)
	gcc $(FLAGS) $(SRC) $(HEADERS)
	ar rv $(NAME) $(subst /includes/,/,$(OBJECTS))
	ranlib $(NAME)
	rm -rf ./output
	mkdir ./output
	mv -f ./*.o ./output
	rm -rf ./includes/*.gch

all:	$(NAME)
	
clean:
	rm -rf $(OBJECTS) ./includes/.*swp ./src/.*swp
	rm -rf ./*.o ./.*gch ./.*swp ./.DS_Store ./.*dSYM

fclean:	clean
	rm -rf $(NAME) ./*.exe ./*.out ./*.stackdump

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
