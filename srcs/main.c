/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:50:40 by qduperon          #+#    #+#             */
/*   Updated: 2016/03/22 16:45:24 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_opt	flags;
	int 	item;
	
	item = ft_parser_opt(ac, av, &flags);
		if (item == ac)
		ft_do_ls(".", flags);
	return (0);
}
