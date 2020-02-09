/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispathdir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:03:44 by mchocho           #+#    #+#             */
/*   Updated: 2020/02/09 16:04:32 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int              ft_ispathdir(char *path)
{
	struct stat             fstat;
	if (stat(path, &fstat) < 0)
		return (0);
	return (S_ISDIR(fstat.st_mode));
}
