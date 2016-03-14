/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:06:17 by qduperon          #+#    #+#             */
/*   Updated: 2016/03/10 18:44:09 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "./../libft/includes/libft.h"
# include <dirent.h>
# include <errno.h>
# include <grp.h>
# include <pwd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/acl.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <time.h>
# include <unistd.h>

# define OPTION "Ralrt"

typedef	struct		s_ls
{
	char	type;
	char	*name;
	char	*link;
	char	*u_name;
	char	*g_name;
	char	*right;
	int	nb_link;
	int	nb_block;
	size_t	size;
	time_t	atime;
	time_t	mtime;
	time_t	stime;
}					t_ls;

typedef	struct		s_option
{
	int	a;
	int 	l;
	int 	rec;
	int 	r;
	int	t;
}					t_opt;

typedef int		(*t_sort)(t_ls*, t_ls*);

/* base_ls.c */
int	ft_do_ls(char *directory_name, t_opt flags);

/* data.c */
t_list	*ft_catch_data(char *arg, t_opt flags);

/* error.c */
void	ft_error(char *s°;
void	ft_error_flags(char c);

/* init.c */
void	ft_ini_struct(t_opt *flags);

/* parser.c */
int	ft_parser_opt(int ac, char **av, t_opt *flags);

/* tools.c */
char	*ft_build_path(char *d_name, char *path);
void	ft_get_info(struct stat *tmp_stat, t_ls *tmp);

/* tools_info.c */
char	ft_grab_type(struct stat *tmp_stat);
char	*ft_grab_right(struct stat *tmp_stat, char *path);

#endif
