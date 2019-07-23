/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printusername.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 09:48:46 by mchocho           #+#    #+#             */
/*   Updated: 2019/07/23 09:51:06 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printusername(char *path)
{
	struct stat		fstat;
	struct passwd	*pw;

	if (stat(path, &stat) < 0)
		return ;

	if (pw = getpwuid(stat.st_uid))
		ft_putstr(pw.pw_name);
	return ;
}
