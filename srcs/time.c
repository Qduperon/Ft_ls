/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 16:08:50 by qduperon          #+#    #+#             */
/*   Updated: 2016/06/13 14:16:25 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*ft_get_time(time_t tm_file)
{
	char	*str_ctime;
	char	*str;

	if (!(str_ctime = ctime(&tm_file)))
		return (NULL);
	if (!(str = ft_strsub(str_ctime, 4, 12)))
		return (NULL);
	return (str);
}

static char	*ft_take_year(time_t tm_file)
{
	char	*str_ctime;
	char	*str1;
	char	*str2;
	char	*str;

	if (!(str_ctime = ctime(&tm_file)))
		return (NULL);
	if (!(str1 = ft_strsub(str_ctime, 4, 7))
			|| !(str2 = ft_strsub(str_ctime, 19, 5)))
		return (NULL);
	if (!(str = ft_strjoin(str1, str2)))
		return (NULL);
	free(str1);
	free(str2);
	return (str);
}

char		*ft_take_time(time_t tm_file)
{
	char		*str;
	char		*(*f)(time_t);
	time_t		tm_now;
	time_t		tm_diff;
	struct tm	*stm_diff;

	if (time(&tm_now) == -1)
		return (NULL);
	if ((tm_diff = tm_now - tm_file) < 0)
		return (NULL);
	if (!(stm_diff = localtime(&tm_diff)))
		return (NULL);
	//if ((stm_diff->tm_mon >= 6) || (stm_diff->tm_year > 1970))
	//	f = ft_take_year;
	else
		f = ft_get_time;
	if (!(str = f(tm_file)))
		return (NULL);
	return (str);
}
