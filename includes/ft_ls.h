/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:38:06 by mchocho           #+#    #+#             */
/*   Updated: 2019/09/17 17:05:45 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H
#include <sys/types.h>
#include <sys/xattr.h>
#include <sys/stat.h>
#include <sys/acl.h>
#include <sys/errno.h>
#include <pwd.h>
#include <unistd.h>
#include <dirent.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <time.h>
#include <stdio.h>
#include "../libft/includes/libft.h"
#define true 1
#define false 0

typedef struct		s_file {
	char		*filename;
	struct	stat	*file_status;
	struct	s_file	*next;
}		t_file;

typedef struct		_linkedlist {
	struct s_file *head;
	struct s_file *tail;
	struct s_file *current;
}		LinkedList;

typedef struct		f_object {
	int	a_flag;
	int	d_flag;
	int	f_flag;
	int	g_flag;
	int	i_flag;
	int	l_flag;
	int	R_flag;
	int	r_flag;
	int	t_flag;
	int	u_flag;
	char	d_flag_value[255];
	int	fod_exclusively;
	int	fod_fromindex;
	int	isvalid;
	int	terminate_ls;
}		flagobject;


int			ft_filetype(struct stat *fstat);
void			ft_addtail(LinkedList *list, char *filename, struct stat *fstat);
void			ft_cleanlist(LinkedList **list);
void			ft_destroyflagship(flagobject **flagship);
int			ft_totalblocks(char *path, int all);
int			ft_filecount(char *path, int all);
void			ft_longlist(t_file *file, flagobject *flagship);
void			ft_ls(int argc, char **argv);
void			ft_initlist(LinkedList *list);
int			ft_isvalidoption(char c);
char			*ft_splicepath(char *path);
void			ft_initflagobject(flagobject *flagship);
void			ft_reverselist(LinkedList *list);
void			ft_scanfile(char *path, flagobject *flagship);
void			ft_sortlist(LinkedList *list, flagobject *flagship);
void			ft_sortbytime(LinkedList *list);
void			ft_sortbyascii(LinkedList *list);
void			ft_sortbynamethenaccess(LinkedList *list);
int			ft_structcmp(t_file *file1, t_file *file2);
void			ft_printlist(LinkedList *list, flagobject *flagship);
char			*ft_parseurl(char *path);

#endif
