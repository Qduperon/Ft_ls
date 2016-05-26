/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 15:36:16 by qduperon          #+#    #+#             */
/*   Updated: 2016/05/26 18:48:03 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_print_link(char *link)
{
	if (link)
	{
		ft_putstr(" -> ");
		ft_putstr(link);
	}
	ft_putchar('\n');
}

static void		ft_print_time(time_t time)
{
	char	*str;

	if (!(str = ft_take_time(time)))
		return ;
	ft_putstr(str);
	ft_putchar(' ');
	free(str);
}

static void		ft_take_long(t_list *list, t_opt flags)
{
	ft_putchar(((t_ls*)(list->content))->type);
	ft_putstr(((t_ls*)(list->content))->right);
	ft_putchar(' ');
	ft_putnbr(((t_ls*)(list->content))->nb_link);
	ft_putchar(' ');
	ft_putstr(((t_ls*)(list->content))->u_name);
	ft_putchar(' ');
	ft_putstr(((t_ls*)(list->content))->g_name);
	ft_putstr("  ");
	ft_putnbr(((t_ls*)(list->content))->size);
	ft_putchar(' ');
	ft_print_time(((t_ls*)(list->content))->mtime);
	ft_putstr(((t_ls*)(list->content))->name);
	ft_print_link(((t_ls*)(list->content))->link);
}

void			ft_print_long(t_list *list, t_opt flags)
{
	if (!list)
		return ;
	while (list)
	{
		ft_take_long(list, flags);
		list = list->next;
	}
}
