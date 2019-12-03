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

#include "../includes/ft_ls.h"

int	ft_structcmp(t_file *file1, t_file *file2)
{
	if (ft_strcmp(file1->filename, file2->filename) == 0)
		if (file1->file_status->st_mtime == file2->file_status->st_mtime)
			return (file1->file_status->st_mtim.tv_nsec == file2->file_status->st_mtim.tv_nsec);
	return (false);
}
