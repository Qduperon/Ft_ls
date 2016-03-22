/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:24:33 by qduperon          #+#    #+#             */
/*   Updated: 2016/03/22 18:07:52 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_do_ls(char *directory_name, t_opt flags)
{
	t_list	*list;
	t_sort	*f_sort;

	if (!(list = ft_catch_data(directory_name, flags)))
		ft_error(directory_name);
//	f_sort = select_sort(flags);
	return (0);
}
