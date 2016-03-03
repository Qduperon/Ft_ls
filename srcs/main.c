/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:50:40 by qduperon          #+#    #+#             */
/*   Updated: 2016/03/03 14:58:21 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_struct	flags;

	ft_ini_struct(flags);
	flags = ft_parser(ac, av, flags);
	ft_print_opt(flags);
 //	ft_check_opt(flags);
 //	ft_do_ls();
	return (0);
}
