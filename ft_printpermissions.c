/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpermissions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 18:04:22 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/06 16:44:48 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_isdir(struct stat fstat)
{
	return (S_ISDIR(fstat.st_mode));
}


void ft_printpermissions(char *path)
{
	struct stat fstat;
	mode_t protected;

	if (stat(path, &fstat) < 0)
		return ;

	protected = fstat.st_mode;

	ft_putchar((ft_isdir(fstat)) ? 'd' : '-');
	ft_putchar((protected & S_IRUSR) ? 'r' : '-');
	ft_putchar((protected & S_IWUSR) ? 'w' : '-');
	ft_putchar((protected & S_IXUSR) ? 'x' : '-');
	ft_putchar((protected & S_IRGRP) ? 'r' : '-');
	ft_putchar((protected & S_IWGRP) ? 'w' : '-');
	ft_putchar((protected & S_IXGRP) ? 'x' : '-');
	ft_putchar((protected & S_IROTH) ? 'r' : '-');
	ft_putchar((protected & S_IWOTH) ? 'w' : '-');
	ft_putchar((protected & S_IXOTH) ? 'x' : '-');
	return ;
}
