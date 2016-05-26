/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 17:46:47 by qduperon          #+#    #+#             */
/*   Updated: 2016/05/26 17:49:26 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_list	*ft_make_arg(char *av)
{
	t_list		*list;
	struct stat	tmp_stat;

	if (lstat(av, &tmp_stat) == -1)
	{
		ft_error(av);
		return (NULL);
	}
	if (!(list = ft_get_file(av, &tmp_stat, av)))
		return (NULL);
	return (list);
}

static void		ft_get_arg(t_list **list_f, t_list **list_s, char *av)
{
	DIR			*tmp_open;
	t_list		*tmp_list;

	if (!(tmp_list = ft_make_arg(av)))
		return ;
	if ((tmp_open = opendir(av)))
		ft_lstadd(list_s, tmp_list);
	else if (errno == ENOTDIR)
		ft_lstadd(list_f, tmp_list);
	else
	{
		ft_free_ls(tmp_list->content, tmp_list->content_size);
		free(tmp_list);
		ft_error(av);
	}
	if (tmp_open)
		closedir(tmp_open);
}

void			ft_split_arg(t_list **list_f, t_list **list_s,
		char **av, int n_av)
{
	int			i;

	i = 0;
	while (i < n_av)
	{
		ft_get_arg(list_f, list_s, av[i]);
		i++;
	}
}
