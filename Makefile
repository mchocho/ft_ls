# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchocho <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 09:51:23 by mchocho           #+#    #+#              #
#    Updated: 2019/08/02 14:10:29 by mchocho          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME: ft_ls.a

HEADERS: ft_ls.h

FLAGS: -Wall -Werror -Wextra

compile:
	gcc $(FLAGS) $(FN)

out:
	./a.out

outW:
	./a.exe
