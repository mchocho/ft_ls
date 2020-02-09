/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseurl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:56:26 by mchocho           #+#    #+#             */
/*   Updated: 2020/02/06 15:57:10 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*ft_parseurl(char *path)
{
	char temp[1024];
	char temp_2[1024];

	ft_bzero(temp, 1);
	ft_bzero(temp_2, 2);
	if (*path == '\0')
		return (path);
	ft_strcpy(temp, path);
	ft_strcpy(temp_2, "./");
	if (temp[ft_strlen(path) - 1] != '/')
		ft_strcat(temp, "/");
	path = ft_strdup(temp);
	return (path);
}
