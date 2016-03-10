/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:24:33 by qduperon          #+#    #+#             */
/*   Updated: 2016/03/10 18:51:04 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_do_ls(char *directory_name, t_opt flags)
{
	t_list	*list;
	t_sort	*f_sort;

	if (!(list = catch_data(directory_name, flags)))
		ft_error(directory_name);
	f_sort = select_sort(opt);
	return (0);
}
