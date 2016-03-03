/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:24:33 by qduperon          #+#    #+#             */
/*   Updated: 2016/03/02 18:01:51 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_do_ls(void)
{
	DIR				*directory;
	struct dirent	*files;

	if ((directory = opendir("./")) == NULL)
		perror("");
	while ((files = readdir(directory)) != NULL)
	{
		if (files->d_name[0] != '.')
		{
			ft_putstr(files->d_name);
			if (files->d_type == DT_DIR)
				ft_do_ls();
			ft_putstr("\n");
		}
	}
	closedir(directory);
	return (0);
}
