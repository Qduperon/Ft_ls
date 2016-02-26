/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:24:33 by qduperon          #+#    #+#             */
/*   Updated: 2016/02/24 19:14:48 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct dirent	ft_check_places(struct dirent *tmp)
{
	int		i;
	struct dirent *temp;
	
	i = 0;
	while (tmp->d_name[i])
	{
		if (ft_strcmp(&tmp->d_name[i], &tmp->d_name[i + 1]) > 0)
		{
			temp->d_name[0] = tmp->d_name[i + 1];
			tmp->d_name[i + 1] = tmp->d_name[i];
			tmp->d_name[i] = temp->d_name[0];
		}
		i++;
	}
	return *(tmp);
}

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
		//	ft_check_places(files);
			ft_putstr(files->d_name);
			if (files->d_type == DT_DIR)
				ft_putstr(" (doss)");
			ft_putstr("\n");
		}
	}
	closedir(directory);
	return (0);
}
