/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:51:03 by qduperon          #+#    #+#             */
/*   Updated: 2016/06/14 15:48:24 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_fill_major(t_list *list)
{
	char	*buff;
	int		len;
	int		max;

	max = 0;
	while (list)
	{
		if (!(buff = ft_itoa(((t_ls*)(list->content))->major)))
			return (-1);
		len = ft_strlen(buff);
		max = (len > max) ? len : max;
		list = list->next;
	}
	return (max);
}

int		ft_fill_minor(t_list *list)
{
	char	*buff;
	int		len;
	int		max;

	max = 0;
	while (list)
	{
		if (!(buff = ft_itoa(((t_ls*)(list->content))->minor)))
			return (-1);
		len = ft_strlen(buff);
		max = (len > max) ? len : max;
		list = list->next;
	}
	return (max);
}
