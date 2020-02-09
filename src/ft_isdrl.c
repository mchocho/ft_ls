/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdrl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 10:52:53 by mchocho           #+#    #+#             */
/*   Updated: 2020/02/09 10:56:15 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_isdrl(char *path)
{
	struct stat fstat;

	if (stat(path, &fstat) < 0)
		return (0);
	return (ft_strichr("drl", ft_filetype(&fstat)) > -1);
}
