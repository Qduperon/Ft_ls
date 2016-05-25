/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:06:17 by qduperon          #+#    #+#             */
/*   Updated: 2016/05/12 18:01:10 by qduperon         ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/xattr.h>
# include <time.h>
# include <unistd.h>

# define BUFF 1024
# define OPTION "Ralrt"

typedef	struct		s_ls
{
	char	type;
	char	*name;
	char	*link;
	char	*u_name;
	char	*g_name;
	char	*right;
	int		nb_link;
	int		nb_block;
	size_t	size;
	time_t	atime;
	time_t	mtime;
	time_t	stime;
}					t_ls;

typedef	struct		s_option
{
	int		a;
	int		l;
	int		rec;
	int		r;
	int		t;
}					t_opt;

typedef int			(*t_exit)(t_ls*, t_ls*);
int					ft_do_ls(char *directory_name, t_opt flags);
t_exit				ft_select_exit(t_opt flags);
void				ft_exit(t_list **list, t_exit exit, t_opt flags);
t_list				*ft_catch_data(char *arg, t_opt flags);
void				ft_link(char *arg, t_opt flags,
		struct dirent *d, t_list **lst);
void				ft_error(char *s);
void				ft_error_flags(char c);
t_list				*ft_get_file(char *d_name, struct stat *tmp_stat, char *path);
int					ft_ascii_cmp(t_ls *content, t_ls *content2);
int					ft_mtime_cmp(t_ls *content, t_ls *content2);
void				ft_ini_struct(t_opt *flags);
int					ft_parser_opt(int ac, char **av, t_opt *flags);
char				*ft_build_path(char *d_name, char *path);
void				ft_get_info(struct stat *tmp_stat, t_ls *tmp);
void				ft_free_ls(t_ls *tmp, size_t size);
char				*ft_grab_grp(gid_t gid);
char				*ft_grab_uid(uid_t uid);
char				ft_grab_type(struct stat *tmp_stat);
char				*ft_grab_right(struct stat *tmp_stat, char *path);
void				ft_print(t_list *list, t_opt flags);
void				ft_print_ls(t_list *list, t_opt flags);
void				ft_check_sticky(char *rights, struct stat *tmp_stat);
void				ft_check_acl_extend(char *rights, char *path);
void				ft_split_arg(t_list **list_f, t_list **list_s, char **av, int n_av);
#endif
