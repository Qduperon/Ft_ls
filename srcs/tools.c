/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 18:30:48 by qduperon          #+#    #+#             */
/*   Updated: 2016/06/14 15:46:46 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_free_ls(t_ls *tmp, size_t size)
{
	free(tmp->name);
	free(tmp->link);
	free(tmp->u_name);
	free(tmp->g_name);
	free(tmp->right);
	ft_bzero(tmp, size);
}

void	ft_get_info(struct stat *tmp_stat, t_ls *tmp)
{
	tmp->major = ft_get_major((int)(tmp_stat->st_rdev));
	tmp->minor = ft_get_minor((int)(tmp_stat->st_rdev));
	tmp->nb_block = (int)(tmp_stat->st_blocks);
	tmp->nb_link = (int)(tmp_stat->st_nlink);
	tmp->size = (size_t)(tmp_stat->st_size);
	tmp->atime = tmp_stat->st_atime;
	tmp->mtime = tmp_stat->st_mtime;
	tmp->stime = tmp_stat->st_ctime;
}

char	*ft_build_path(char *d_name, char *path)
{
	char *tmp_path;
	char *new_path;

	if (!(tmp_path = ft_strjoin(path, "/")))
		return (NULL);
	if (!(new_path = ft_strjoin(tmp_path, d_name)))
	{
		free(tmp_path);
		return (NULL);
	}
	free(tmp_path);
	return (new_path);
}

int		ft_get_major(int dev)
{
	while ((dev / 256) > 0)
		dev = dev / 256;
	return (dev);
}

int		ft_get_minor(int dev)
{
	int minor;

	minor = dev % 256;
	return (minor);
}
