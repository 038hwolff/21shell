/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:32:14 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/27 14:50:57 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** ft_manage_inhib_ctrl :
** Retourne -1 si un Ctrl C ou un Ctrl D a été capté, 0 sinon.
*/

// A METTRE DANS EDITION DE LGNE
int		check_eof(t_data *data)
{
	return (data->eof != 0 && !(data->shell_exit = 0) && !(data->eof = 0));
}

int		check_cancel(t_data *data, char **line)
{
	if (check_if_sigint(data, line))
		return (-1);
	if (check_eof(data))
	{
		eof_exception();
		free(*line);
		return (-1);
	}
	return (0);
}

/*
** complete_tokens :
** Complète la fin du token du dernier maillon de lex. Puis passe le reste au
** lexer et ajoute à la suite de lex les nouveaux tokens.
*/

void	complete_tokens(t_token *token, int incomp_type, char *line)
{
	token = get_last_token(token);
	ft_printf("lol\n");
	if (incomp_type == INC_QUOTE)
		complete_command_quote(token, &line, '\'');
	else if (incomp_type == INC_DQUOTE)
		complete_command_quote(token, &line, '"');
	else if (incomp_type == INC_BKSLASH)
		complete_command_backslash(token, &line);
	ft_printf("lal\n");
	token = get_last_token(token);
	lexical_analysis(&token, line);
	print_lex(token);

	//ft_lexlst_remove_if(token, "", 0);
}

void set_prompt(t_edl *data, char *prompt, size_t prompt_len)
{
	data->edl.prompt = prompt;
	data->edl.prompt_len = prompt_len;
}

void display_special_prompt(t_data *data)
{
	if (data->incomp_type == INC_QUOTE)
		set_prompt(data, PQUOTE, PQUOTE_LEN);
	else if (data->incomp_type == INC_DQUOTE)
		set_prompt(data, PDQUOTE, PDQUOTE_LEN);		
	else if (data->incomp_type == INC_BKSLASH)
		set_prompt(data, PBACKSLASH, PBACKSLASH_LEN);
	else if (data->incomp_type == INC_HEREDOC)
		set_prompt(data, PHEREDOC, PHEREDOC_LEN);
	else
		set_prompt(data, PDEFAULT, PDEFAULT_LEN);
	display_prompt(data);
}


/*
** check_command :
** Vérifie les fermetures de doubles et simples quotes, et des back-slashs.
** Vérifie si les pipes, double and et double pipe possèdent une deuxième
** commande simple après l'opérateur de contrôle.
** Rend la main à l'utilisateur si nécessaire => vérifie donc à chaque fois les
** erreurs de syntaxe, le ctrl_d, et split la chaine de char récupérée dans les
** bons maillons.
*/

int		check_command(t_data *data, t_token **token)
{
	//char	*neartoken;

	if (!token || !(*token))
		return (-1);
	while ((data->incomp_type = check_incomplete_command(*token)) != COMPLETE)
	{
		display_special_prompt(data);
		read_line();
		if (check_cancel(data, &data->edl.line) == -1)
			return (-1);
		complete_tokens(*token, data->incomp_type, data->edl.line);
		//if ((neartoken = check_syntax_errors(*token)) != NULL)
		//{
		//	syntax_exception(neartoken);
		//	return (-1);
		//}
	}
	return (0);
}
