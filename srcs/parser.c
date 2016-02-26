/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:25:13 by qduperon          #+#    #+#             */
/*   Updated: 2016/02/26 17:45:14 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
static t_struct	ft_check_flag(char *s, t_struct flags)
{
	int		i;

	i = 0;
	ft_ini_struct(flags);
	while (s[++i])
	{
		if (s[i] == 'a')
			flags.a = 1;
		else if (s[i] == 'l')
			flags.l = 1;
		else if (s[i] == 'R')
			flags.rec = 1;
		else if (s[i] == 'r')
			flags.r = 1;
		else if (s[i] == 't')
			flags.t = 1;
		else
			ft_error_flags(s[i]);
	}
	return (flags);
}

static int	ft_check_directory(char *s)
{
	DIR				*directory;
	struct dirent 	*files;
	int				i;

	if ((directory = opendir("./")) == NULL)
		perror("");
	while ((files = readdir(directory)) != NULL)
	{
		i = -1;
		while (files->d_name[++i])
		{
			if (ft_strcmp(s, &files->d_name[i]) == 0)
				return (0);
		}
	}
	return (-1);
}

int		ft_parser(int ac, char **av, t_struct flags)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (!(av[1]) || ft_strcmp(av[1], "--") == 0)
		return (0);
	while (i < ac && j == 0)
	{
		if (av[i][0] == '-' && av[i][1] != '-')
		{
			flags = ft_check_flag(av[i], flags);
			i++;
		}
		else if (av[i][0] == '-' && av[i][1] == '-')
			i++;
		else if (av[i][0] != '-')
			j = 1;
	}
	while (i < ac)
	{	
		if (ft_check_directory(av[i]))
			ft_error_directory(av[i]);
		i++;
	}
	return (0);
}
