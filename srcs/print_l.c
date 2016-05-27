/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 15:36:16 by qduperon          #+#    #+#             */
/*   Updated: 2016/05/27 17:27:05 by qduperon         ###   ########.fr       */
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

static void		ft_take_long(t_list *list, t_opt flags, t_max max)
{
	ft_putchar(((t_ls*)(list->content))->type);
	ft_putstr(((t_ls*)(list->content))->right);
	ft_putchar(' ');
	ft_putstr_right(ft_itoa(((t_ls*)(list->content))->nb_link), max.max_link);
	ft_putchar(' ');
	ft_putstr_left(((t_ls*)(list->content))->u_name, max.max_uname);
	ft_putchar(' ');
	ft_putstr_left(((t_ls*)(list->content))->g_name, max.max_gname);
	ft_putstr("  ");
	ft_putstr_right(ft_itoa(((t_ls*)(list->content))->size), max.max_size);
	ft_putchar(' ');
	ft_print_time(((t_ls*)(list->content))->mtime);
	ft_putstr(((t_ls*)(list->content))->name);
	ft_print_link(((t_ls*)(list->content))->link);
}

static int		ft_block(t_list *list)
{
	int block;
	
	block = 0;
	while (list)
	{
		block = block + ((t_ls*)(list->content))->nb_block;
		list = list->next;
	}
	return (block);
}

void			ft_print_long(t_list *list, t_opt flags)
{
	t_max max;

	ft_fill_max(&max, list);
	if (!list)
		return ;
	ft_putstr("total ");
	ft_putnbr(ft_block(list));
	ft_putchar('\n');
	while (list)
	{
		ft_take_long(list, flags, max);
		list = list->next;
	}
}
