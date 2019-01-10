/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:43:23 by hwolff            #+#    #+#             */
/*   Updated: 2019/01/10 12:11:31 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** 1      [1]    32000 hangup     bash --posix
** 2     rien
** 3     rien
** 4    [1]    32336 illegal hardware instruction  bash --posix
** 5    [1]    32364 trace trap  bash --posix
** 6    [1]    32506 abort      bash --posix
** 7    [1]    32625 EMT instruction  bash --posix
** 8    [1]    32706 floating point exception  bash --posix
** 9    [1]    32782 killed     bash --posix      (SGKILL IMPOS A RECUP)
** 10   [1]    32811 bus error  bash --posix
** 11	[1]    32852 segmentation fault  bash --posix
** 12	[1]    32909 invalid system call  bash --posix
** 13		-Rien- quitte juste
** 14 	  [2]    33836 alarm      bash --posix
** 15   fait rien
** 16   fait rien
** 17 [1]  + 33605 suspended (signal)  bash --posix(SIGSTOP IMPOSS A RECUP)
** 18   fait rien
** 19 [1]  + 33992 continued  bash --posix
** 20   fait rien
** 21   fait rien
** 22   fait rien
** 23   fait rien
** 24 [1]    33576 cpu limit exceeded  bash --posix
** 25 [1]    33519 file size limit exceeded  bash --posix
** 26 [1]    33496 virtual time alarm  bash --posix
** 27 [1]    33432 profile signal  bash --posix
** 28   fait rien
** 29   fait rien
** 30 [1]    33362 user-defined signal 1  bash --posix
** 31 [1]    33297 user-defined signal 2  bash --posix
*/

void	put_signal(t_data *data, int sig)
{
	static const char *mes[31] = {"hangup", "", "",
		"illegal hardware instruction", "trace trap", "abort",
		"EMT instruction", "floating point exception", "", "bus error",
		"segmentation fault", "invalid system call", "", "alarm", "", "",
		"suspended", "", "continued", "", "", "", "", "cpu limit exceeded",
		"file size limit exceeded", "virtual time alarm", "profile signal",
		"", "", "user-defined signal 1", "user-defined signal 2"};

	ft_dprintf(STDERR_FILENO, "  %s %s  %s\n", "", mes[sig - 1],
		data->arguments ? data->arguments : "");
}

void	signal_handler(int sig)
{
	t_data	*data;

	data = get_data();
	if (sig == SIGINT)
		handle_sigint(data);
	else if (sig == 1
		|| (sig >= 4 && sig <= 8)
		|| (sig >= 10 && sig <= 14)
		|| (sig >= 24 && sig <= 27)
		|| (sig >= 30 && sig <= 31))
	{
		put_signal(data, sig);
		exit_program(128 + sig);
	}
}

void	handle_sigint(t_data *data)
{
	data->sigint = 1;
	ft_putchar_fd('\n', 1);
	display_prompt(&data->edl);
	ft_strdel(&data->edl.line);
	try_m(data->edl.line = ft_strnew(0));
	data->edl.index = 0;
	signal(SIGINT, signal_handler);
}

void	signal_list(void)
{
	int	i;

	i = 0;
	while (++i < 32)
		signal(i, signal_handler);
}
