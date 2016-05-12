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
		ft_putendl_fd(strerror(errno), 2);
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
		ft_putendl_fd(strerror(errno), 2);
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
	rights[0] = (tmp_stat->st_mode & S_IRWXU) ||\
				(tmp_stat->st_mode & S_IRWXU) ? 'r' : '-';
	rights[1] = (tmp_stat->st_mode & S_IWUSR) ||\
				(tmp_stat->st_mode & S_IRWXU) ? 'w' : '-';
	rights[2] = (tmp_stat->st_mode & S_IXUSR) ||\
				(tmp_stat->st_mode & S_IRWXU) ? 'x' : '-';
	rights[3] = (tmp_stat->st_mode & S_IRGRP) ||\
				(tmp_stat->st_mode & S_IRWXG) ? 'r' : '-';
	rights[4] = (tmp_stat->st_mode & S_IWGRP) ||\
				(tmp_stat->st_mode & S_IRWXG) ? 'w' : '-';
	rights[5] = (tmp_stat->st_mode & S_IXGRP) ||\
				(tmp_stat->st_mode & S_IRWXG) ? 'x' : '-';
	rights[6] = (tmp_stat->st_mode & S_IROTH) ||\
				(tmp_stat->st_mode & S_IRWXO) ? 'r' : '-';
	rights[7] = (tmp_stat->st_mode & S_IWOTH) ||\
				(tmp_stat->st_mode & S_IRWXO) ? 'w' : '-';
	rights[8] = (tmp_stat->st_mode & S_IXOTH) ||\
				(tmp_stat->st_mode & S_IRWXO) ? 'x' : '-';
	rights[9] = ' ';
	return (rights);
}
