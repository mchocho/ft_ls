/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:38:06 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/30 17:25:23 by mchocho          ###   ########.fr       */
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
#include "libft/libft.h"
#define true 1
#define false 0

typedef struct c_timeobject {
	char day[4];
	char month[4];
	char date[3];
	char hours[3];
	char minutes[3];
	char seconds[3];
	char year[5];
	char *ctime;
	time_t epoch;
}		ctimeobject;

typedef struct s_file {
	char *filename;
	struct ctimeobject *lastmodified;
	struct ctimeobject *accesstime;
	struct s_file *next;
	struct s_file *prev;
}		t_file;


typedef struct _linkedlist {
	struct s_file *head;
	struct s_file *tail;
	struct s_file *current;
}		LinkedList;

typedef struct f_object {
	int	a_flag;
	int	l_flag;
	int	r_flag;
	int	R_flag;
	int	t_flag;
	int u_flag;
	int f_flag;
	int g_flag;
	int d_flag;
	int	fod_exclusively;
	int	fod_fromindex;
	int	isvalid;
	int	terminate_ls;
	char	error_message[256];
}		flagobject;


int				ft_ispathdir(char *path);
off_t			ft_totalsize(char *path, int all);
//int			ft_totalblocks(char *path, int all);
//int			ft_filecount(char *path, int all);
int			ft_detectfiletype(mode_t mode);
int			ft_detectfilepathtype(char *path);
void			ft_printpermissions(char *path);
void			ft_printusername(char *path);
void			ft_printgroupname(char *path);
void			ft_printdatetime(char *path);
void			ft_longlist(char *path, int all);
void			ft_ls(char **argv, int argc);
void			ft_printfiles_t(char *path, int all, int recursive, int longL);
void			ft_printfiles_r(char *path, int all, int recursive, int longL);
ctimeobject		*ft_constructctimeobj(time_t value);
void			ft_initlist(LinkedList *list);
void			ft_addhead(LinkedList *list, char *filename, ctimeobject *lm, ctimeobject *acc);
void			ft_addtail(LinkedList *list, char *filename, ctimeobject *lm, ctimeobject *acc);
char			*ft_splicepath(char *path);
int				ft_hardlinkcount(char *path, int all, int recursive);
void			ft_initflagobject(flagobject *flagship);
void			ft_reverselist(LinkedList *list);
void			ft_scanfile(char *path, flagobject *flagship);
void			ft_sortlist(LinkedList *list, flagobject *flagship);
void			ft_sortbytime(LinkedList *list);
void			ft_sortybyascii(LinkedList *list);
void			ft_printlist(LinkedList *list, flagobject *flagship);


#endif
