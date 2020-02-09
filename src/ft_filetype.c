/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detectfiletype.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:28:03 by mchocho           #+#    #+#             */
/*   Updated: 2020/02/09 10:46:49 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	ft_filetype(struct stat *fstat)
{
	mode_t mode;

	mode = fstat->st_mode;
	if (S_ISDIR(mode))
		return ('d');
	else if (S_ISREG(mode))
		return ('r');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISFIFO(mode))
		return ('p');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	else
		return (0);
}
