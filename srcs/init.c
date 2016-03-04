/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:18:30 by qduperon          #+#    #+#             */
/*   Updated: 2016/03/03 18:40:29 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_struct ft_ini_struct(t_struct flags)
{
	flags.a = 0;
	flags.l = 0;
	flags.rec = 0;
	flags.r = 0;
	flags.t = 0;
	return (flags);
}

void	ft_get_tab(char **tab, int i, char *s)
{
	int item;

	item = ft_strlen(s);
	tab[i] = malloc(sizeof(char) * item);
	tab[i] = ft_strcpy(tab[i], s);
}

void	ft_clear_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}
