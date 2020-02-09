/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assembleflagship.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 11:02:20 by mchocho           #+#    #+#             */
/*   Updated: 2020/02/09 16:29:57 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		ft_handleoptions(flagobject *flagship, char option)
{
	if (option == 'l')
		flagship->l_flag = true;
	else if (option == 'r')
		flagship->r_flag = true;
	else if (option == 'R')
		flagship->R_flag = true;
	else if (option == 't')
		flagship->t_flag = true;
	else if (option == 'u')
		flagship->u_flag = true;
	else if (option == 'f')
		flagship->f_flag = true;
	else if (option == 'g')
		flagship->g_flag = true;
	else if (option == 'd')
		flagship->d_flag = true;
	else if (option == 'i')
		flagship->i_flag = true;
	else if (option == 'a')
		flagship->a_flag = true;
	else if (option == 'o')
		flagship->o_flag = true;
}

void			ft_assembleflagship(char *flag, flagobject *flagship)
{
	int i;

	if (flagship == NULL)
		return ;
	i = 0;
	while (flag[i])
	{
		if (!ft_isvalidoption(flag[i]) || ft_strichr(flag, '-') > 1)
		{
			ft_errormessage(1, (ft_strichr(flag, '-') > 1) ? '-' : flag[i], "");
			flagship->terminate_ls = true;
			return ;
		}
		else
			ft_handleoptions(flagship, flag[i]);
		i++;
	}
}
