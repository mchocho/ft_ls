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
	struct timespec f1;
	struct timespec f2;

	f1 = file1->file_status.st_mtim;
	f2 = file2->file_status.st_mtim;
	if (ft_strcmp(file1->filename, file2->filename) == 0)
		if (file1->file_status.st_mtime == file2->file_status.st_mtime)
			return (f1.tv_nsec == f2.tv_nsec);
	return (false);
}
