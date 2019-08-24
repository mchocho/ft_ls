/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalidoption.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:35:46 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/24 16:36:54 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_isvalidoption(char c)
{
	char	*options;

	options = "[-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1]\n";
	return (ft_strchr(options, c) ? true : false);
}
