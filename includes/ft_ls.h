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
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <stdio.h>

# define OPTION "ARalrt1cgu"

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
	int one;
	int	g;
	int c;
	int u;
	int	a;
	int	aa;
	int l;
	int rec;
	int r;
	int	t;
}					t_opt;

typedef int		(*t_sort)(t_ls*, t_ls*);

int					ft_do_ls(char *directory_name, t_opt flags);
int					ft_check_directory(char *s, char *name);
int					ft_strlen_slash(char *s);
int					ft_check_after_slash(char *s);
t_struct			ft_fill_the_array(t_struct flags, char *s, int i, int item);
int					ft_parser_opt(int ac, char **av, t_opt *flags);
void				ft_ini_struct(t_struct flags);
void				ft_clear_tab(t_struct flags);
t_struct			ft_get_tab(t_struct flags, int i, char *s);
void				ft_error(char *s);
void				ft_error_flags(char c);
void				ft_print_opt(t_struct flags);

#endif
