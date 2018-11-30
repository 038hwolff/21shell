/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:32:14 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/27 14:27:34 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** ft_parser :
** Check les erreurs de syntax.
** Gère les inhibiteurs.
** Supprime les tokens de type NEW_LINE.
** Récupère les arguments du hdoc.
** Renvoie -1 si syntax error ou signal d'interruption, 0 sinon.
*/

int		parser(t_token **token)
{
	t_data			*data;
	char			*neartoken;
	int				new_line;

	if (!token)
		return (0);
	data = get_data();
	if ((neartoken = check_syntax_errors(*token)) != NULL)
	{
		syntax_exception(neartoken);
		return (-1);
	}
	if (check_command(data, token) == -1)
		return (-1);
	
	ft_printf("\nend\n\n");

/// -> here
	new_line = NEWLINE;
	//ft_lexlst_remove_if(token, &new_line, 1);
	

	//if (check_heredoc(*token, data) == -1)
	//	return (-1);
	

	//if (data->flags->token == 1)
	//	ft_put_lexlst(*token);
	

	return (0);
}
