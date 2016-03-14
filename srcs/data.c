#include "ft_ls.h"

static t_list	ft_get_file(char *d_name, struct stat *tmp_stat, char *path)
{
	t_list 	list;
	t_ls	tmp;
	
	errno = 0;
	if (!d_name || !tmp_stat)
		return (NULL);
	ft_get_info(tmp_stat, &tmp);
	if (!(tmp.name = ft_strdup(d_name)) || \ 
            !(tmp.type = ft_grab_type(tmp_stat)) || \
	    !(tmp.right = ft_grab_right(tmp_stat, path)))
		return (NULL);
}

static t_list	ft_build_link(char *arg, char *d_name)
{
	char 	*path;
	struct 	stat tmp_stat;
	t_list	list;

	if (!(path = ft_build_path(d_name, arg)))
		return (NULL);
	if(!(lstat(path, &tmp_stat)))
		ft_error(path);
	if(!(list = ft_get_file(d_name, &tmp_stat, path)))
		return (NULL);
	free(path);
	return (list);
}

static void	ft_directory_link(char *arg, t_opt flags, struct dirent directory, t_list **list)
{
	t_list	*tmp;
	
	tmp = NULL;
	if (flags.a)
	{
		if (!(tmp = ft_build_link(arg, directory->d_name)))
			return ;
		ft_lstadd(list, tmp);
	}
	else if (*directory->d_name != ".")
	{
		if (!(tmp = ft_build_link(arg, directory->d_name)))
			return ;
		ft_lstadd(list, tmp);
	}
}

t_list		*ft_catch_data(char *arg, t_opt flags)
{
	DIR		*tmp;
	struct dirent 	directory;
	t_list		*list;
	
	list = NULL;
	errno = 0;
	if ((tmp = opendir(arg)))
	{
		while (directory = readdir(tmp))
			ft_directory_link(arg, flags, directory, &list);
		closedir(tmp);
	}
	return (list);
}
