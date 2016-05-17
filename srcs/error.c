/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:45:48 by qduperon          #+#    #+#             */
/*   Updated: 2016/03/22 16:47:31 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error(char *s)
{
	ft_putstr("ft_ls: ");
	ft_putstr(s);
	ft_putchar(':');
	ft_putchar(' ');
	ft_putendl(strerror(errno));
}

void	ft_error_flags(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putendl("usage: ft_ls [-ARalrt1cgu] [file ...]");
}
