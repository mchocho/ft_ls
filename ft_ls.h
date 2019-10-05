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
#include "libft/libft.h"
#define true 1
#define false 0

typedef struct		s_file {
	char	*filename;
	time_t	lastmodified;
	time_t	accesstime;
	struct	s_file *next;
}		t_file;

typedef struct		_linkedlist {
	struct s_file *head;
	struct s_file *tail;
	struct s_file *current;
}		LinkedList;

typedef struct		f_object {
	int	a_flag;
	int	l_flag;
	int	r_flag;
	int	R_flag;
	int	t_flag;
	int	u_flag;
	int	f_flag;
	int	g_flag;
	int	d_flag;
	int	fod_exclusively;
	int	fod_fromindex;
	int	isvalid;
	int	terminate_ls;
}		flagobject;


int			ft_ispathdir(char *path);
off_t			ft_totalsize(char *path, int all);
int			ft_totalblocks(char *path, int all);
int			ft_filecount(char *path, int all);
int			ft_detectfiletype(mode_t mode);
int			ft_detectfilepathtype(char *path);
void			ft_printpermissions(char *path);
void			ft_printusername(char *path);
void			ft_printgroupname(char *path);
void			ft_printdatetime(char *path);
void			ft_longlist(char *path, flagobject *flagship);
void			ft_ls(int argc, char **argv);
void			ft_initlist(LinkedList *list);
int			ft_isvalidoption(char c);
void			ft_addhead(LinkedList *list, char *filename, time_t lm, time_t acc);
void			ft_addtail(LinkedList *list, char *filename, time_t lm, time_t acc);
char			*ft_splicepath(char *path);
void			ft_cleanlist(LinkedList **list);
int			ft_hardlinkcount(char *path, int all, int recursive);
void			ft_initflagobject(flagobject *flagship);
void			ft_reverselist(LinkedList *list);
void			ft_scanfile(char *path, flagobject *flagship);
void			ft_sortlist(LinkedList *list, flagobject *flagship);
int			ft_nsecondscmp(char *fn1, char *fn2, int tv);
void			ft_sortbytime(LinkedList *list);
void			ft_sortbyascii(LinkedList *list);
void			ft_sortbynamethenaccess(LinkedList *list);
int			ft_structcmp(t_file *file1, t_file *file2);
void			ft_printlist(LinkedList *list, flagobject *flagship);
char			*ft_parseurl(char *path);
void			ft_verifyflag(char *flag, flagobject *flagship);

#endif
