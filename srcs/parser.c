/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:25:13 by qduperon          #+#    #+#             */
/*   Updated: 2016/03/22 16:23:48 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_check_flag(char s, t_opt *flags)
{
	if (s == 'a')
		flags->a = 1;
	if (s == 'l')
		flags->l = 1;
	if (s == 'R')
		flags->rec = 1;
	if (s == 'r')
		flags->r = 1;
	if (s == 't')
		flags->t = 1;
}

static void		ft_pars_opt(char *str, t_opt *flags)
{
	int c;

	c = 1;
	while (str[c])
	{
		if (!ft_strchr(OPTION, str[c]))
		{
			ft_error_flags(str[c]);
			exit(1);
		}
		else
			ft_check_flag(str[c], flags);
		c++;
	}
}

int				ft_parser_opt(int ac, char **av, t_opt *flags)
{
	int i;

	i = 1;
	ft_ini_struct(flags);
	if (!(av[1]) || ft_strcmp(av[1], "--") == 0)
		return (i);
	while (i < ac && av[i][0] == '-')
	{
		if (!av[i][1])
			return (i);
		ft_pars_opt(av[i], flags);
		i++;
	}
	return (i);
}
