/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:56:36 by qduperon          #+#    #+#             */
/*   Updated: 2016/05/26 17:55:22 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*ft_get_time(time_t time_file)
{
	char	*str_ctime;
	char	*str;

	if (!(str_ctime = ctime(&time_file)))
		return (NULL);
	if (!(str = ft_strsub(str_ctime, 4, 12)))
		return (NULL);
	return (str);
}

static char	*ft_take_year(time_t time_file)
{
	char	*str_ctime;
	char	*str1;
	char	*str2;
	char	*str;

	if (!(str_ctime = ctime(&time_file)))
		return (NULL);
	if (!(str1 = ft_strsub(str_ctime, 4, 7)) ||
			!(str2 = ft_strsub(str_ctime, 19, 5)))
		return (NULL);
	if ((str = ft_strjoin(str1, str2)))
		return (NULL);
	free(str1);
	free(str2);
	return (str);
}

char		*ft_take_time(time_t time_file)
{
	char		*str;
	char		*(*f)(time_t);
	time_t		time_now;
	time_t		time_diff;
	struct tm	*stime_diff;

	if (!(time_file))
		return (NULL);
	if ((time_diff = time_now - time_file) < 0)
		return (NULL);
	if (!(stime_diff = localtime(&time_diff)))
		return (NULL);
	if ((stime_diff->tm_mon >= 6) || (stime_diff->tm_year >= 1970))
		f = ft_take_year;
	else
		f = ft_get_time;
	if (!(str = f(time_file)))
		return (NULL);
	return (str);
}
