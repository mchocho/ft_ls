/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispathdir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:52:32 by mchocho           #+#    #+#             */
/*   Updated: 2019/07/25 12:04:37 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int ft_ispathdir(char *path)
{
	struct stat fstat;

	if (stat(path, &fstat) < 0)
		return (0);

	return (S_ISDIR(fstat.st_mode));
}
