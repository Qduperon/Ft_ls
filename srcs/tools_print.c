/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 14:44:56 by qduperon          #+#    #+#             */
/*   Updated: 2016/05/27 17:53:14 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_putstr_right(char *str, int with)
{
	int len;
	int diff;

	len = (int)ft_strlen(str);
	if ((diff = with - len) >= 0)
	{
		while ((diff--))
			ft_putchar(' ');
		ft_putstr(str);
	}
	else
	{
		diff *= -1;
		while (diff <= len && str[diff])
		{
			ft_putchar(str[diff]);
			diff++;
		}
	}
}

void		ft_putstr_left(char *str, int with)
{
	while (*str && with)
	{
		ft_putchar(*str++);
		with--;
	}
	while ((with--))
		ft_putchar(' ');
}
