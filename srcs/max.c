/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 14:07:19 by qduperon          #+#    #+#             */
/*   Updated: 2016/05/27 17:52:00 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_fill_link(t_list *list)
{
	char	*buff;
	int		len;
	int		max;

	max = 0;
	while (list)
	{
		if (!(buff = ft_itoa(((t_ls*)(list->content))->nb_link)))
			return (-1);
		len = ft_strlen(buff);
		max = (len > max) ? len : max;
		list = list->next;
	}
	return (max);
}

static int		ft_fill_uname(t_list *list)
{
	int len;
	int max;

	max = 0;
	while (list)
	{
		len = ft_strlen(((t_ls*)(list->content))->u_name);
		max = (len > max) ? len : max;
		list = list->next;
	}
	return (max);
}

static int		ft_fill_gname(t_list *list)
{
	int	len;
	int	max;

	max = 0;
	while (list)
	{
		len = ft_strlen(((t_ls*)(list->content))->g_name);
		max = (len > max) ? len : max;
		list = list->next;
	}
	return (max);
}

static int		ft_fill_size(t_list *list)
{
	char	*buff;
	int		len;
	int		max;

	max = 0;
	while (list)
	{
		if (!(buff = ft_itoa(((t_ls*)(list->content))->size)))
			return (-1);
		len = ft_strlen(buff);
		max = (len > max) ? len : max;
		list = list->next;
	}
	return (max);
}

void			ft_fill_max(t_max *max, t_list *list)
{
	max->max_link = ft_fill_link(list);
	max->max_uname = ft_fill_uname(list);
	max->max_gname = ft_fill_gname(list);
	max->max_size = ft_fill_size(list);
}
