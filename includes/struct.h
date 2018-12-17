/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:19:20 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/17 11:25:17 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/*
** Typedef / Structs
*/

typedef void		(*t_sighandler)(int);

/*
** Token for lexer
*/

typedef struct		s_token
{
	char			*val;
	size_t			length;
	int				type;
	char			*heredoc;
	struct s_token	*next;
}					t_token;

/*
** AST
*/

typedef struct		s_ast
{
	t_token			*token;
	t_token			*left_arg;
	t_token			*right_arg;

	struct s_ast	*right;
	struct s_ast	*left;
	int				type;
}					t_ast;

typedef struct		s_var
{
	char			*key;
	char			*val;
}					t_var;

typedef struct		s_hist
{
	char			**list;
	int				h_count;
	int				h_current;
	char			*copy;
}					t_hist;

typedef struct		s_edl
{
	int				index;
	int				*light;
	int				c_light;
	char			*line;
	int				multiline;
	int				col;
}					t_edl;

typedef struct		s_cdenv
{
	char			*old;
	char			*pwd;
	char			*home;
}					t_cdenv;

/*
** DONNES PRINCIPALES DU SHELL !!!
*/

typedef struct		s_data
{
	char			*term_name;
	char			*prompt;
	size_t			prompt_len;
	int				incomp_type;

	char			**env;
	t_var			*loc;
	char			**args;

	char			*cmd_line;
	char			*additional_line;

	t_token			*token;
	t_ast			*ast;

	int				childpid;

	struct termios	term_dft_config;

	short			shell_exit;
	int				errno;

	int				sigint;
	int				eof;

	t_edl			edl;
	t_hist			hist;

	int				exe_return;
}					t_data;

/*
**	Structure utile uniquement dans l'objet d'expansion
**		=> Contient l'ensemble des regles d'expansion
**		=> Un lien vers votre env
*/

typedef struct	s_varsexp	t_varsexp;

/*
**	Definition du type representant une regles d'expansion pour les variables
*/

typedef struct		s_varsexp_rules
{
	char			*op;
	char			*(*set)(t_varsexp *exp, char *key, char *val, char *word);
	char			*(*null)(t_varsexp *exp, char *key, char *val, char *word);
	char			*(*unset)(t_varsexp *exp, char *key, char *val, char *word);
}					t_varsexp_rules;

struct				s_varsexp
{
	t_data			*data;
	char			*str;
	char			*res;
	t_varsexp_rules	*rule;
	char			format;
};

#endif
