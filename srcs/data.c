/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:38:33 by qduperon          #+#    #+#             */
/*   Updated: 2016/06/13 14:11:36 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*ft_readlink(t_ls tmp, char *path)
{
	char			*link;

	if (!(link = ft_strnew(BUFF)))
		return (NULL);
	if (tmp.type == 'l')
		if (readlink(path, link, BUFF) > 0)
			return (link);
	free(link);
	return (NULL);
}

t_list			*ft_get_file(char *d_name, struct stat *tmp_stat, char *path)
{
	t_list			*list;
	t_ls			tmp;

	errno = 0;
	if (!d_name || !tmp_stat)
		return (NULL);
	ft_get_info(tmp_stat, &tmp);
	if (!(tmp.name = ft_strdup(d_name)) ||\
			!(tmp.type = ft_grab_type(tmp_stat)) ||\
			!(tmp.right = ft_grab_right(tmp_stat, path)) ||\
			!(tmp.u_name = ft_grab_uid(tmp_stat->st_uid)) ||\
			!(tmp.g_name = ft_grab_grp(tmp_stat->st_gid)))
		return (NULL);
	tmp.link = ft_readlink(tmp, path);
	if (!(list = ft_lstnew(&tmp, sizeof(tmp))))
	{
		ft_free_ls(&tmp, tmp.size);
		return (NULL);
	}
	return (list);
}

static t_list	*ft_build_link(char *arg, char *d_name)
{
	char			*path;
	struct stat		tmp_stat;
	t_list			*list;

	if (!(path = ft_build_path(d_name, arg)))
		return (NULL);
	if (lstat(path, &tmp_stat) == -1)
	{
		ft_error(path);
		return (NULL);
	}
	if (!(list = ft_get_file(d_name, &tmp_stat, path)))
		return (NULL);
	free(path);
	return (list);
}

void			ft_link(char *arg, t_opt flags, struct dirent *d, t_list **lst)
{
	t_list			*tmp;

	if (flags.a)
	{
		if (!(tmp = ft_build_link(arg, d->d_name)))
			return ;
		ft_lstadd(lst, tmp);
	}
	else if (*(d->d_name) != '.')
	{
		if (!(tmp = ft_build_link(arg, d->d_name)))
			return ;
		ft_lstadd(lst, tmp);
	}
}

t_list			*ft_catch_data(char *arg, t_opt flags)
{
	DIR				*tmp;
	struct dirent	*directory;
	t_list			*list;

	list = NULL;
	errno = 0;
	if ((tmp = opendir(arg)))
	{
		while ((directory = readdir(tmp)))
			ft_link(arg, flags, directory, &list);
		closedir(tmp);
	}
	return (list);
}
