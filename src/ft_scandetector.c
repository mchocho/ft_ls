/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scandetector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:35:50 by mchocho           #+#    #+#             */
/*   Updated: 2020/02/09 13:39:04 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_scandetector(flagobject *fs, int ac, char **av, int target)
{
	int i;

	i = 0;
	if (target && ac)
		while (i < ac)
		{
			if (ft_isdrl(av[i]))
				ft_scanfile(av[i], fs);
			i++;
		}
	else
		ft_scanfile("./", fs);
	return ;
}
