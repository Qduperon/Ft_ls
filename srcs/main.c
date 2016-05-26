/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:50:40 by qduperon          #+#    #+#             */
/*   Updated: 2016/05/26 17:52:07 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_free_arg(t_list **list_f, t_list **list_s)
{
	if (*list_f)
		ft_lstdel(list_f, (void(*)(void*, size_t))ft_free_ls);
	if (list_s)
		ft_lstdel(list_s, (void(*)(void*, size_t))ft_free_ls);
}

static void	ft_deal_dir(t_list *list_d, t_opt flags, int ac, int item)
{
	while (list_d)
	{
		if (ac - item > 1)
		{
			ft_putstr(((t_ls*)(list_d->content))->name);
			ft_putchar(':');
			ft_putchar('\n');
		}
		ft_do_ls(((t_ls*)(list_d->content))->name, flags);
		list_d = list_d->next;
		if (list_d)
			ft_putchar('\n');
	}
}

int			main(int ac, char **av)
{
	t_opt		flags;
	int			item;
	t_list		*list_f;
	t_list		*list_s;
	t_exit		select_arg;

	list_f = NULL;
	list_s = NULL;
	item = ft_parser_opt(ac, av, &flags);
	if (item == ac)
		ft_do_ls(".", flags);
	else
	{
		ft_split_arg(&list_f, &list_s, av + item, ac - item);
		select_arg = ft_select_exit(flags);
		ft_exit(&list_f, select_arg, flags);
		ft_exit(&list_s, select_arg, flags);
		ft_print(list_f, flags);
		if (list_f && list_s)
			ft_putchar('\n');
		ft_deal_dir(list_s, flags, ac, item);
		ft_free_arg(&list_f, &list_s);
	}
	return (0);
}
