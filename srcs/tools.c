/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 18:30:48 by qduperon          #+#    #+#             */
/*   Updated: 2016/03/07 18:45:06 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_strlen_slash(char *s)
{
	int i;

	i = 0;

	while (s[i] && s[i] != '/')
		i++;
	return (i);
}

int		ft_check_after_slash(char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != '/')
		i++;
	while (s[i] && s[i] == '/')
		i++;
	if (s[i])
		return (1);
	else
		return (0);
}
