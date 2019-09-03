/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:10:42 by mchocho           #+#    #+#             */
/*   Updated: 2019/09/02 14:19:10 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_structcmp(t_file *file1, t_file *file2)
{
	if (ft_strcmp(file1->filename, file2->filename) == 0)
		return (file1->lastmodified->epoch == file2->lastmodified->epoch);
	return (false);
}
