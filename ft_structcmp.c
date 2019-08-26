/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:10:42 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/26 18:12:38 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_structcmp(t_file *file1, t_file *file2)
{
	if (ft_strcmp(file1->filename, file2->filename))
		return (file1->epoch == file2->epoch);
	return (false);
}
