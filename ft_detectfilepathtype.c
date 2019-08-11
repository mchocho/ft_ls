/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detectfilepathtype.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:12:36 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/09 15:46:13 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_detectfilepathtype(char *path)
{
	struct stat fstat;

	if (lstat(path, &fstat) < 0)
		return (0);

	return (ft_detectfiletype(fstat.st_mode));
}
