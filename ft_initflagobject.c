/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initflagobject.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:25:33 by mchocho           #+#    #+#             */
/*   Updated: 2019/09/02 14:25:40 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_initflagobject(flagobject *flagship)
{
        flagship->a_flag = false;
        flagship->l_flag = false;
        flagship->r_flag = false;
        flagship->R_flag = false;
        flagship->t_flag = false;
        flagship->u_flag = false;
        flagship->f_flag = false;
        flagship->g_flag = false;
        flagship->d_flag = false;
        flagship->fod_exclusively = false;
		flagship->fod_fromindex = -1;
        flagship->isvalid = true;
        flagship->terminate_ls = false;
		return ;
}
