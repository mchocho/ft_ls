/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:05:23 by mchocho           #+#    #+#             */
/*   Updated: 2019/07/25 12:10:56 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_longlist(char *path, int all)
{
	//Print file permissions
	ft_printpermission(path);
	ft_putchar('\t');
	//Print # of files
	if (ft_ispathdir(path))
		ft_putstr(ft_itoa(ft_filecount(path)));
	else
		ft_putchar('1');
	ft_putchar('\t');
				
}
