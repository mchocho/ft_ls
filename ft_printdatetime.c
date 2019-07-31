/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdatetime.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:08:06 by mchocho           #+#    #+#             */
/*   Updated: 2019/07/31 18:20:50 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct stat 	fstat;
char			**timearr;
char			*lastmodified;

if (ft_detectfileptype(path) == 'r')
{
	if (stat(path, &fstat) < 0)
		return ;
} else if (ft_detectfileptype(path) == 'l')	//ft_detectfilepathtype
{
	if (lstat(path, &fstat) < 0)
		return ;
} else
	return ;

if (!(lastmodified = ))
