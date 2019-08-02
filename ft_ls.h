/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:38:06 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/02 16:51:01 by mchocho          ###   ########.fr       */
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
#include "libft/libft.h"
#define TRUE 1
#define FALSE 0

int ft_ispathdir(char *path);
int ft_totalsize(char *path);
int ft_totalblocks(char *path);
int ft_filecount(char *path);
static int ft_detectfiletype(mode_t mode);
static int ft_detectfiletypepath(char *path);
static void ft_printpermissions(char *path);
static void ft_printusername(char *path);
static void ft_printgroupname(char *path);
static void ft_printdatetime(char *path);
void ft_longlist(char *path);
void ft_listdir(char *path, int all, int recursive, int longL);//, char sortby);


#endif
