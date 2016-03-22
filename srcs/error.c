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
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(s, 2);
	ft_putchar_fd(':', 2);
	ft_putchar_fd(' ', 2);
	ft_putendl_fd(strerror(errno), 2);
	exit(1);
}

void	ft_error_flags(char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd("usage: ft_ls [-ARalrt1cgu] [file ...]", 2);
	exit(1);
}
