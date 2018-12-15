/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:52:58 by hben-yah          #+#    #+#             */
/*   Updated: 2018/08/09 20:04:11 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long
	days_to_year(long long *days)
{
	long	year;
	long	nb;

	year = 1970;
	while (*days >= (nb = ((year % 4 == 0) && (year % 100 != 0) ? 366 : 365)))
	{
		*days -= nb;
		++year;
	}
	return (year);
}

static t_date
	*sec_to_date(long long second, t_date *date)
{
	static const long	days_in_month[2][12] = {
		{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
		{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
	};
	long long			days;
	long				nb;
	int					bix;

	days = second / 86400;
	date->sec = second % 86400 % 60;
	date->min = second % 86400 % 3600 / 60;
	date->hour = second % 86400 / 3600;
	date->year = days_to_year(&days);
	date->month = 0;
	bix = (date->year % 4 == 0) && (date->year % 100 != 0);
	while (days >= (nb = days_in_month[bix][date->month]))
	{
		days -= nb;
		++date->month;
	}
	date->day = days + 1;
	return (date);
}

static void
	long_to_date(t_strbuffer *sb, t_date *date)
{
	static const char	*months[12] = {
		"Janvier", "Février", "Mars", "Avril",
		"Mai", "Juin", "Juillet", "Août",
		"Septembre", "Octobre", "Novembre", "Décembre"};
	char				*tmp;

	trial((tmp = ft_itoa(date->day)) != NULL);
	add(sb, tmp, ft_strlen(tmp));
	free(tmp);
	add(sb, " ", 1);
	add(sb, months[date->month], ft_strlen(months[date->month]));
	add(sb, " ", 1);
	trial((tmp = ft_itoa(date->year)) != NULL);
	add(sb, tmp, ft_strlen(tmp));
	free(tmp);
}

static void
	long_to_time(t_strbuffer *sb, t_date *date)
{
	char *tmp;

	if (date->hour < 10)
		add(sb, "0", 1);
	trial((tmp = ft_itoa(date->hour)) != NULL);
	add(sb, tmp, ft_strlen(tmp));
	free(tmp);
	add(sb, ":", 1);
	if (date->min < 10)
		add(sb, "0", 1);
	trial((tmp = ft_itoa(date->min)) != NULL);
	add(sb, tmp, ft_strlen(tmp));
	free(tmp);
	add(sb, ":", 1);
	if (date->sec < 10)
		add(sb, "0", 1);
	trial((tmp = ft_itoa(date->sec)) != NULL);
	add(sb, tmp, ft_strlen(tmp));
	free(tmp);
}

int	convert_k(t_formatter *fmt, t_strbuffer *sb, va_list ap)
{
	long long	arg;
	t_date		date;

	arg = va_arg(ap, long long);
	if (fmt->precision == 1)
		long_to_time(sb, sec_to_date(arg, &date));
	else if (fmt->precision >= 2)
	{
		long_to_date(sb, sec_to_date(arg, &date));
		add(sb, "  ", 2);
		long_to_time(sb, sec_to_date(arg, &date));
	}
	else
		long_to_date(sb, sec_to_date(arg, &date));
	return (1);
}
