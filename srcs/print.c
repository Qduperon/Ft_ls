/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:44:09 by qduperon          #+#    #+#             */
/*   Updated: 2016/05/12 18:20:45 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_ls(t_list *list, t_opt flags)
{
	while (list)
	{
		ft_putendl(((t_ls*)(list->content))->name);
		list = list->next;
	}
}

static void	(*ft_select(t_opt flags))(t_list*, t_opt)
{
	//if (flags.l)
	//	return (ft_print_l);
	//else
	return (ft_print_ls);
		//return (void(*)(t_list*, t_opt))(ft_print_ls);
}

void	ft_print(t_list *list, t_opt flags)
{
	void	(*f_print)(t_list*, t_opt);

	f_print = ft_select(flags);
	f_print(list, flags);
}
