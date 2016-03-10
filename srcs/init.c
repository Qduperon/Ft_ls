/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:18:30 by qduperon          #+#    #+#             */
/*   Updated: 2016/03/10 18:06:08 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ini_struct(t_opt *flags)
{
	flags->one = 0;
	flags->aa = 0;
	flags->g = 0;
	flags->c = 0;
	flags->u = 0;
	flags->a = 0;
	flags->l = 0;
	flags->rec = 0;
	flags->r = 0;
	flags->t = 0;
}

t_struct	ft_get_tab(t_struct flags, int i, char *s)
{
	int item;

	item = ft_strlen(s);
	flags.tab[i] = malloc(sizeof(char) * item);
	flags.tab[i] = ft_strcpy(flags.tab[i], s);
	return (flags);
}

void	ft_clear_tab(t_struct flags)
{
	int i;

	i = 0;
	while (flags.tab[i])
	{
		free(flags.tab[i]);
		i++;
	}
}
