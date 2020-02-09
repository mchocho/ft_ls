/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splicepath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:49:45 by mchocho           #+#    #+#             */
/*   Updated: 2020/02/06 15:56:01 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*ft_splicepath(char *path)
{
	if (ft_strrchr(path, '/'))
		return ((ft_strrchr(path, '/') + 1));
	else if (ft_strrchr(path, '\\'))
		return ((ft_strrchr(path, '\\') + 1));
	else
		return (path);
}
