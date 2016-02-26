/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:06:17 by qduperon          #+#    #+#             */
/*   Updated: 2016/02/26 17:19:43 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "./../libft/includes/libft.h"
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <stdio.h>

typedef	struct		s_struct
{
	int	a;
	int l;
	int rec;
	int r;
	int	t;
}					t_struct;

int					ft_do_ls(void);
int					ft_parser(int ac, char **av, t_struct flags);
t_struct			ft_ini_struct(t_struct flags);
void				ft_error_directory(char *s);
void				ft_error_flags(char c);

#endif
