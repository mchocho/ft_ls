/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:38:06 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/12 17:34:21 by mchocho          ###   ########.fr       */
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

int	ft_ispathdir(char *path);
int	ft_totalsize(char *path);
int	ft_totalblocks(char *path);
int	ft_filecount(char *path);
int	ft_detectfiletype(mode_t mode);
int	ft_detectfilepathtype(char *path);
void	ft_printpermissions(char *path);
void	ft_printusername(char *path);
void	ft_printgroupname(char *path);
void	ft_printdatetime(char *path);
void	ft_longlist(char *path);
void	ft_ls(char *path, int all, int recursive, int longL, char sortby);
void	ft_printfiles_t(char *path, int all, int recursive, int longL);
void	ft_printfiles_r(char *path, int all, int recursive, int longL);
void	ft_constructctimeobj(const time_t value);
void	ft_initlist(LinkedList *list);
void	ft_addhead(LinkedList *list, char *filename, ctimeobject lm);
void	ft_addtail(LinkedList *list, char *filename, ctimeobject lm);

typedef struct s_file {
	char *filename;
	struct ctimeobject lasmodified;
	struct s_file *next;
	struct s_file *prev;
}		t_file;

typedef struct _ctimeobject {
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

typedef struct _linkedlist {
	s_file *head;
	s_file *tail;
	s_file *current;
}		LinkedList

#endif
