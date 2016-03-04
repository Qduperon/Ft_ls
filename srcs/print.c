/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 18:01:59 by qduperon          #+#    #+#             */
/*   Updated: 2016/03/03 15:52:56 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_opt(t_struct flags)
{
	int i;

	i = 0;
	ft_putendl("Option a :");
	ft_putnbr(flags.a);
	ft_putchar('\n');
	ft_putendl("Option l :");
	ft_putnbr(flags.l);
	ft_putchar('\n');
	ft_putendl("Option R :");
	ft_putnbr(flags.rec);
	ft_putchar('\n');
	ft_putendl("Option r :");
	ft_putnbr(flags.r);
	ft_putchar('\n');
	ft_putendl("Option t :");
	ft_putnbr(flags.t);
	ft_putchar('\n');
	ft_putendl("Files :");
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}
