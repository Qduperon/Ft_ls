/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:24:29 by qduperon          #+#    #+#             */
/*   Updated: 2016/05/12 15:31:04 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_grab_grp(gid_t gid)
{
	struct group	*group;
	char			*grp;

	errno = 0;
	if (!(group = getgrgid(gid)))
	{
		ft_putendl(strerror(errno));
		return (NULL);
	}
	if (!(grp = ft_strdup(((char *)group->gr_name))))
		return (NULL);
	return (grp);
}

char	*ft_grab_uid(uid_t uid)
{
	struct passwd	*password;
	char			*person;

	errno = 0;
	if (!(password = getpwuid(uid)))
	{
		ft_putendl(strerror(errno));
		return (NULL);
	}
	if (!(person = ft_strdup(((char *)password->pw_name))))
		return (NULL);
	return (person);
}

char	ft_grab_type(struct stat *tmp_stat)
{
	if ((tmp_stat->st_mode & S_IFMT) == S_IFSOCK)
		return ('s');
	if ((tmp_stat->st_mode & S_IFMT) == S_IFLNK)
		return ('l');
	if ((tmp_stat->st_mode & S_IFMT) == S_IFREG)
		return ('-');
	if ((tmp_stat->st_mode & S_IFMT) == S_IFBLK)
		return ('b');
	if ((tmp_stat->st_mode & S_IFMT) == S_IFDIR)
		return ('d');
	if ((tmp_stat->st_mode & S_IFMT) == S_IFCHR)
		return ('c');
	if ((tmp_stat->st_mode & S_IFMT) == S_IFIFO)
		return ('p');
	return ('\0');
}

char	*ft_grab_right(struct stat *tmp_stat, char *path)
{
	char *rights;

	if (!(rights = ft_strnew(10)))
		return (NULL);
	rights[0] = (tmp_stat->st_mode & S_IRWXU) ? 'r' : '-';
	rights[1] = (tmp_stat->st_mode & S_IWUSR) ? 'w' : '-';
	rights[2] = (tmp_stat->st_mode & S_IXUSR) ? 'x' : '-';
	rights[3] = (tmp_stat->st_mode & S_IRGRP) ? 'r' : '-';
	rights[4] = (tmp_stat->st_mode & S_IWGRP) ? 'w' : '-';
	rights[5] = (tmp_stat->st_mode & S_IXGRP) ? 'x' : '-';
	rights[6] = (tmp_stat->st_mode & S_IROTH) ? 'r' : '-';
	rights[7] = (tmp_stat->st_mode & S_IWOTH) ? 'w' : '-';
	rights[8] = (tmp_stat->st_mode & S_IXOTH) ? 'x' : '-';
	rights[9] = ' ';
	ft_check_sticky(rights, tmp_stat);
	ft_check_acl_extend(rights, path);
	return (rights);
}
