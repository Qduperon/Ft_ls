/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:03:50 by qduperon          #+#    #+#             */
/*   Updated: 2016/06/14 15:46:20 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ascii_cmp(t_ls *content, t_ls *content2)
{
	return (ft_strcmp(content->name, content2->name));
}

int		ft_mtime_cmp(t_ls *content, t_ls *content2)
{
	if (content->mtime < content2->mtime)
		return (1);
	else if (content->mtime > content2->mtime)
		return (-1);
	else
		return (ft_ascii_cmp(content, content2));
}
