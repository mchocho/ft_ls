/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errormessage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 10:58:42 by mchocho           #+#    #+#             */
/*   Updated: 2020/02/09 11:00:22 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_errormessage(int err, char c, char *file)
{
	ft_putstr(RED);
	ft_putstr("ls: ");
	if (err == 0)
		ft_putstr("unknown option ");
	else if (err == 404)
	{
		ft_putstr("Cannot access '");
		ft_putstr(file);
		ft_putstr("': No such file or directory\n");
		return ;
	}
	else
		ft_putstr("illegal option ");
	ft_putstr("-- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putstr(NO_COL);
}
