/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:24:33 by qduperon          #+#    #+#             */
/*   Updated: 2016/05/27 15:46:30 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_exit			ft_select_exit(t_opt flags)
{
	if (flags.t)
		return ((t_exit)ft_mtime_cmp);
	else
		return ((t_exit)ft_ascii_cmp);
}

static	void	ft_recursive(t_list *list, char *directory_name, t_opt flags)
{
	char *path;

	while (list)
	{
		if (!(path = ft_build_path(((t_ls *)(list->content))->name,
						directory_name)))
			return ;
		if (((t_ls *)(list->content))->type == 'd'
				&& ft_strcmp(((t_ls *)(list->content))->name, ".")
				&& ft_strcmp(((t_ls *)(list->content))->name, ".."))
		{
			ft_putchar('\n');
			ft_putstr(path);
			ft_putchar(':');
			ft_putchar('\n');
			ft_do_ls(path, flags);
		}
		free(path);
		list = list->next;
	}
}

int				ft_do_ls(char *directory_name, t_opt flags)
{
	t_list	*list;
	t_exit	f_exit;

	if (!(list = ft_catch_data(directory_name, flags)))
	{
		ft_error(directory_name);
		return (1);
	}
	f_exit = ft_select_exit(flags);
	ft_exit(&list, (t_exit)f_exit, flags);
	ft_print(list, flags);
	if (flags.rec)
		ft_recursive(list, directory_name, flags);
	ft_lstdel(&list, (void (*)(void *, size_t))ft_free_ls);
	return (0);
}
