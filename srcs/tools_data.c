/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 17:55:39 by qduperon          #+#    #+#             */
/*   Updated: 2016/06/14 15:47:12 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_check_sticky(char *rights, struct stat *tmp_stat)
{
	if (tmp_stat->st_mode & S_ISUID)
	{
		if (rights[2] == 'x')
			rights[2] = 's';
		else
			rights[2] = 'S';
	}
	if (tmp_stat->st_mode & S_ISGID)
	{
		if (rights[5] == 'x')
			rights[5] = 's';
		else
			rights[5] = 'S';
	}
	if (tmp_stat->st_mode & S_ISVTX)
	{
		if (rights[8] == 'x')
			rights[8] = 't';
		else
			rights[8] = 'T';
	}
}

void	ft_check_acl_extend(char *rights, char *path)
{
	char	buff[BUFF];
	ssize_t	nb_xat;
	acl_t	tmp;

	errno = 0;
	if ((tmp = acl_get_file(path, ACL_TYPE_EXTENDED)))
	{
		acl_free((void *)tmp);
		rights[9] = '+';
	}
	if ((nb_xat = listxattr(path, buff, BUFF, XATTR_NOFOLLOW) &&
				ft_strstr(path, "dev") == 0))
		rights[9] = '@';
}
