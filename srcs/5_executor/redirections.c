/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:08:32 by hwolff            #+#    #+#             */
/*   Updated: 2018/11/23 15:51:42 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
** > : redirige dans un fichier et l'écrase s'il existe déjà ;
** >> : redirige à la fin d'un fichier et le crée s'il n'existe pas.
** < : envoie le contenu d'un fichier à une commande ;
** << : passe la console en mode saisie au clavier, ligne par ligne (heredoc).
**	Toutes ces lignes seront envoyées à la commande lorsque le mot-clé de fin
**	aura été écrit.
** <>
*/

static int	exec_back_redirect(t_data *data)
{
	char	buf;
	int		ret;
	pid_t	pid;
	int		file[2];

	ret = open(data->args[1], O_CREAT | O_WRONLY, 0666);
	if (ret >= 0)
	{
		pid = fork();
		dup2(file[0], 1);
		close(file[0]);
		while (read(file[1], &buf, 1) > 0)
			write(file[0], &buf, 1);
		write(STDOUT_FILENO, "\n", 1);
		is_builtins(data);
	}
	else
	{
		ft_dprintf(STDERR_FILENO, ""ERR_PREFIX"error -- %s\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

static int	exec_redirect(t_data *data, int rafter)
{
	char	buf;
	int		ret;
	pid_t	pid;
	int		file[2];

	if (rafter == 1)
		ret = open(data->args[2], O_CREAT | O_WRONLY, 0666);
	else if (rafter == 2)
		ret = open(data->args[2], O_APPEND);
	if (ret >= 0)
	{
		pid = fork();
		dup2(file[1], 1);
		close(file[1]);
		while (read(file[0], &buf, 1) > 0)
			write(file[1], &buf, 1);
		write(STDOUT_FILENO, "\n", 1);
		is_builtins(data);
	}
	else
	{
		ft_dprintf(STDERR_FILENO, ""ERR_PREFIX"error -- %s\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

int			main_redirec(t_data *data, char *raft)
{
	int		rafter;

	if (data && raft)
	{
		if (ft_strequ(raft, ">") == 1 || ft_strequ(raft, ">>") == 1)
		{
			rafter = (ft_strequ(raft, ">") == 1) ? 1 : 2;
			exec_redirect(data, rafter);
		}
		if (ft_strequ(raft, "<") == 1)
			exec_back_redirect(data);
		if (ft_strequ(raft, "<<") == 1)
			exec_heredoc(data);
		return (1);
	}
	return (0);
}
