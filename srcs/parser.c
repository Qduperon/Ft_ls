/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:25:13 by qduperon          #+#    #+#             */
/*   Updated: 2016/02/26 14:33:15 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_error_directory(char **av)
{
	char	*str;
	
	str = av[1];
	ft_putstr("ls: ");
	ft_putstr(str);
	ft_putendl(": No such file or directory");
	exit(1);
}

static int	ft_check_directory(char **av)
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
			if (ft_strcmp(av[1], &files->d_name[i]) == 0)
				return (0);
		}
	}
	return (-1);
}

int		ft_parser(int ac, char **av)
{
	char	flags;

	flags = 0;
	if (!(av[1]) || ft_strcmp(av[1], "--") == 0)
		return (0);
	else if (ft_check_directory(av))
		ft_error_directory(av);
	return (0);
}
