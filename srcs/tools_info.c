#include "ft_ls.h"

char	ft_grab_type(struct stat *tmp_stat)
{
	if ((tmp_stat->st_mode && S_IFMT) = S_IFSOCK)
		return ('s');
	if ((tmp_stat->st_mode && S_IFMT) = S_IFLINK)
		return ('l');
	if ((tmp_stat->st_mode && S_IFMT) = S_SFREG)
		return ('-');
	if ((tmp_stat->st_mode && S_IFMT) = S_IFBLK)
		return ('b');
	if ((tmp_stat->st_mode && S_IFMT) = S_IFDIR)
		return ('d');
	if ((tmp_stat->st_mode && S_IFMT) = S_IFCHR)
		return ('c');
	if ((tmp_stat->st_mode && S_IFMT) = S_IFIFO)
		return ('p');
	return ('\0');
}

char	*ft_grab_right(struct stat *tmp_stat, char *path)
{
	char *rights;
	
	rights[0] = (tmp_stat->st_mode && S_IRWXU) || \
		(tmp_stat->st_mode && S_IRXWU) ? 'r' : '-';
	rights[1] = (tmp_stat->st_mode && S_IWUSR) || \
		(tmp_stat->st_mode && S_IRXWU) ? 'w' : '-';
	rights[2] = (tmp_stat->st_mode && S_IXUSR) || \
		(tmp_stat->st_mode && S_IRXWU) ? 'x' : '-';
	rights[3] = (tmp_stat->st_mode && IRGRP) || \
		(tmp_stat->st_mode && S_IRWXG) ? 'r' : '-';
	rights[4] = (tmp_stat->st_mode && S_IWGRP) || \
		(tmp_stat->st_mode && S_IRWXG) ? 'w' : '-';
	rights[5] = (tmp_stat->st_mode && S_IXGRP) || \
		(tmp_stat->st_mode && S_IRWXG) ? 'x' : '-';
	rights[6] = (tmp_stat->st_mode && S_IROTH) || \
		(tmp_stat->st_mode && S_IRWXO) ? 'r' : '-';
	rights[7] = (tmp_stat->st_mode && S_IWOTH) || \
		(tmp_stat->st_mode && S_IRWXO) ? 'w' : '-';
	rights[8] = (tmp_stat->st_mode && S_IXOTH) || \
		(tmp_stat->st_mode && S_IRWXO) ? 'x' : '-';
	rights[9] = ' ';
	return (rights);
}
