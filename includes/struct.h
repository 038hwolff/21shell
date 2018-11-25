/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:19:20 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/20 17:25:53 by hben-yah         ###   ########.fr       */
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
	struct s_token	*next;
}					t_token;

/*
** AST
*/

typedef struct		s_ast
{
	int		pouet;
}					t_ast;

typedef struct	s_variable
{
	char	*key;
	char	*val;
}				t_variable;


/*
typedef struct		s_built
{
	char			**av;
	int				ac;
	t_data			*env;
}					t_built;
*/

typedef struct		s_env
{
	int				width;
	int				height;
	char			**words;
	int				word_count;
	int				current_word;
	int				single_col_width;
	struct termios	term;
}					t_env;

typedef struct		s_hist
{
	char				**list;
	int				h_count;
	int				h_current;
}			t_hist;

typedef struct		s_edl
{
	int				index;
	char			*line;
	int				multiline;
/*	char			**hist;
	int				h_count;
	int				h_current;*/
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
	char			*term_name;			// nom du terminal
	int				prompt_len;

	t_variable		*env;				// variables d'environnement
	t_variable		*loc;				// variables locales
	char			**args; 			// vient du minishell, toujours utile ??

	char			*cmd_line; 			// la ligne de commande lue et envoyée au lexer
	t_token			*token;				// le resultat du lexer !!
	t_ast			ast;				// l'arbre syntaxique

	int				childpid;			// pour le fork

	struct termios	term_dft_config; 	// config par defaut du terminal

	short			shell_exit;			// si a reçu un signal de sortie
	int				errno;				// numero d'erreur retourné, notre propre errno 
	t_edl			edl;			
}					t_data;

#endif
