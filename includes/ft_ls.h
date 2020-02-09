/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:38:06 by mchocho           #+#    #+#             */
/*   Updated: 2020/02/09 14:19:14 by mchocho          ###   ########.fr       */
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
#define NO_COL		"\033[0m"
#define BOLD		"\033[1m"
#define BLACK		"\033[30m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define BROWN		"\033[33m"
#define BLUE		"\033[34m"
#define MAGENTA		"\033[35m"
#define CYAN		"\033[36m"
#define GRAY		"\033[37m"
#define YELLOW		"\033[0;33m"

typedef struct		s_file {
	char		*filename;
	struct	stat	file_status;
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
	int	o_flag;
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


int				ft_filetype(struct stat *fstat);
void			ft_addtail(LinkedList *list, char *filename, struct stat *fstat);
void			ft_cleanlist(LinkedList **list);
void			ft_destroyflagship(flagobject **flagship);
int				ft_filecount(char *path, int all);
void			ft_longlist(t_file *file, flagobject *flagship);
void			ft_ls(int argc, char **argv);
void			ft_initlist(LinkedList *list);
int				ft_isvalidoption(char c);
char			*ft_splicepath(char *path);
void			ft_swapnodes(LinkedList *list, t_file **next, t_file **previous);
void			ft_initflagobject(flagobject *flagship);
void			ft_reverselist(LinkedList *list);
void			ft_scanfile(char *path, flagobject *flagship);
void			ft_sortlist(LinkedList *list, flagobject *flagship);
void			ft_sortbytime(LinkedList *list, int time);
void			ft_sortbyascii(LinkedList *list);
int				ft_structcmp(t_file *file1, t_file *file2);
void			ft_printlist(LinkedList *list, flagobject *flagship);
char			*ft_parseurl(char *path);
int				ft_isdrl(char *path);
void			ft_errormessage(int err, char c, char *file);
void			ft_assembleflagship(char *flag, flagobject *flagship);
void			ft_scandetector(flagobject *fs, int ac, char **av, int target);

#endif
