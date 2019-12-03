/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:05:23 by mchocho           #+#    #+#             */
/*   Updated: 2019/12/03 14:13:04 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void ft_printpermissions(struct stat *fstat)
{
	mode_t protected;
	
	if (fstat == NULL)
		return ;
	protected = fstat->st_mode;
	ft_putchar((S_ISDIR(protected)) ? 'd' : '-');
	ft_putchar((protected & S_IRUSR) ? 'r' : '-');
	ft_putchar((protected & S_IWUSR) ? 'w' : '-');
	ft_putchar((protected & S_IXUSR) ? 'x' : '-');
	ft_putchar((protected & S_IRGRP) ? 'r' : '-');
	ft_putchar((protected & S_IWGRP) ? 'w' : '-');
	ft_putchar((protected & S_IXGRP) ? 'x' : '-');
	ft_putchar((protected & S_IROTH) ? 'r' : '-');
	ft_putchar((protected & S_IWOTH) ? 'w' : '-');
	ft_putchar((protected & S_IXOTH) ? 'x' : '-');
	return ;
}

static void	ft_printusername(struct stat *fstat)
{
	struct passwd		*pw;
	
	if (fstat == NULL)
		return ;
	if ((pw = getpwuid(fstat->st_uid)))
		ft_putstr(pw->pw_name);
	return ;
}

static void	ft_printgroupname(struct stat *fstat)
{
	struct group		*gr;

	if (fstat == NULL)
		return ;
	else if ((gr = getgrgid(fstat->st_gid)))
		ft_putstr(gr->gr_name);
	return ;
}

static void ft_printdatetime(struct stat *fstat)
{
	char			**timearr;
	char			*lastmodified;

	if (fstat == NULL)
		return ;
	else if (!(lastmodified = ctime(&(fstat->st_mtime))))
		return ;
	
	timearr = ft_strsplit(lastmodified, ' ');
	ft_putstr(timearr[1]);
	ft_putchar(' ');
	ft_putstr(timearr[2]);
	ft_putchar(' ');
	ft_putstr(ft_strsplit(timearr[3], ':')[0]);
	ft_putchar(':');
	ft_putstr(ft_strsplit(timearr[3], ':')[1]);
	return ;
}

void	ft_longlist(t_file *file, flagobject *flagship)
{
	if (file == NULL || flagship == NULL)
		return ;
	//Print file permissions
	ft_printpermissions(file->file_status);
	ft_putchar(' ');
	//Print # of hardlinks
	if (ft_filetype(file->file_status))
		ft_putnbr((int)file->file_status->st_nlink);//ft_hardlinkcount(file->filename, all, true));//ft_filecount(path, all));
	//else
	//	ft_putpaddedstr("1", 10);
	ft_putchar(' ');
	//Print username
	ft_printusername(file->file_status);
	ft_putchar(' ');
	//Print groupname
	ft_printgroupname(file->file_status);
	ft_putchar(' ');
	//Print total file/directory size
	ft_putnbr((int)file->file_status->st_size);//ft_totalsize(path, all));
	ft_putchar(' ');
	//Print date and time
	ft_printdatetime(file->file_status);
	ft_putchar(' ');
	//Print file/directory name
	ft_putstr(ft_splicepath(file->filename));		//Remove path reference
	ft_putchar('\n');
}
