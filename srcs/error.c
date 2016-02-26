/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:45:48 by qduperon          #+#    #+#             */
/*   Updated: 2016/02/26 17:34:16 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error_directory(char *s)
{
	ft_putstr("ft_ls: ");
	ft_putstr(s);
	ft_putendl(": No such a file or directory");
	exit(1);
}

void	ft_error_flags(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putendl("usage: ft_ls [-Ralrt] [file ...]");
	exit(1);
}
