/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splicepath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:49:45 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/15 17:55:29 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char *ft_splicepath(char *path)
{
	if (ft_strrchr(path, '/'))					//Mac, Linux
		return ((ft_strrchr(path, '/') + 1));
	else if (ft_strrchr(path, '\\'))				//Windows
		return ((ft_strrchr(path, '\\') + 1));
	else
		return (path);
}
