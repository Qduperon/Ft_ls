/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 15:10:53 by qduperon          #+#    #+#             */
/*   Updated: 2016/05/12 16:17:21 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_list	*ft_split(t_list *list)
{
	t_list	*tmp;

	if (!list)
		return (NULL);
	else if (!list->next)
		return (NULL);
	else
	{
		tmp = list->next;
		list->next = tmp->next;
		tmp->next = ft_split(list->next);
		return (tmp);
	}
}

static	t_list	*ft_fusion(t_list *list, t_list *tmp, t_exit exit, t_opt flags)
{
	int signe;

	signe = (flags.r) ? -1 : 1;
	if (!list)
		return (tmp);
	else if (!tmp)
		return (list);
	else if (signe * exit(list->content, tmp->content) < 0)
	{
		list->next = ft_fusion(list->next, tmp, exit, flags);
		return (list);
	}
	else
	{
		tmp->next = ft_fusion(list, tmp->next, exit, flags);
		return (tmp);
	}
}

void			ft_exit(t_list **list, t_exit exit, t_opt flags)
{
	t_list *tmp;

	if (*list)
		if ((*list)->next)
		{
			tmp = ft_split(*list);
			ft_exit(list, exit, flags);
			ft_exit(&tmp, exit, flags);
			*list = ft_fusion(*list, tmp, exit, flags);
		}
}
