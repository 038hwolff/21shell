/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:46:54 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/01 18:44:33 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

/*
** Headers
*/

# include <stdio.h>
# include <sys/ioctl.h>
# include <termios.h>

/*
** Bonus headers
*/

# include <dirent.h>

/*
** Libft
*/

# include "libft.h"
# include <term.h>

/*
** Defines
*/

# define ERR_PREFIX "21sh: "

/*
** KEYBOARD
*/

# define ENTER ((buf[0] == 10 && buf[1] == 0 )|| (buf[0] == 13 && buf[1] == 0))
# define SUPP (buf[0] == 127 && buf[1] == 0)
# define DEL (buf[0] == 27 && buf[1] == 91 && buf[2] == 51 && buf[3] == 126)
# define HAUT (buf[0] == 27 && buf[1] == 91 && buf[2] == 65)
# define BAS (buf[0] == 27 && buf[1] == 91 && buf[2] == 66)
# define GAUCHE (buf[0] == 27 && buf[1] == 91 && buf[2] == 68)
# define DROITE (buf[0] == 27 && buf[1] == 91 && buf[2] == 67)

/*
** Typedef / Structs
*/

typedef void	(*t_sighandler)(int);

typedef struct	s_data
{
	char			*term_name;
	char			**env;
	char			**args;
	char			*entry;
	int				childpid;
	short			on;
	struct termios	prev_term;
}				t_data;

typedef struct	s_built
{
	char		**av;
	int			ac;
	t_data		*env;
}				t_built;

typedef struct	s_env
{
	int		width;
	int		height;
	char		**words;
	int		word_count;
	int		current_word;
	int		single_col_width;
	struct termios	term;
}		t_env;

typedef struct	s_var
{
	int	echo;
	int	index;
	char	*line;
	int	multiline;
	char	**history;
	int	h_count;
}		t_var;

typedef struct	s_cdenv
{
	char		*old;
	char		*pwd;
	char		*home;
}				t_cdenv;

/*
** GLOBALS
*/

t_data		g_sh_data;
int			g_reset_entry;


/*
*****************************************************************************************
************************************* SHELL *********************************************
*****************************************************************************************
*/

/*
** shell.c
*/

t_data			*get_data(void);
int				shell(int ac, char **av, char **env);
int				sh_putchar(int c);

/*
** reset.c
*/

void			reset_shell(t_data *data);

/*
** free.c
*/

void			free_data(t_data *data);

/*
** exit.c
*/

void			exit_program(char *message);

/*
** exception.c
*/

void			*try_m(void *ptr);
void			term_exception(char *message);
void			tent_exception(char *ent);


/*
*****************************************************************************************
************************************* CORE **********************************************
*****************************************************************************************
** shell.c
*/

int				minishell(int argc, char **argv, char **envp);
void			display_prompt(void);

/*
** shell.c
*/

int				ft_enter(char *line, t_var *var);

/*
** loop.c
*/

void			loop(t_env *env);

/*
** setup.c
*/

void			setup_env(int ac, char **av, t_env *);
t_var			*setup_var(t_var *var);

/*
** shell.c
*/

void			handle_signal(int signal);
char			**get_path(t_data *data);
char			**split_for_display(char *entry);
int				global_parse(t_data *data);
int				minishell(int ac, char **av, char **env);

/*
** read.c
*/

int				read_entry(t_data *data);

/*
** parse.c
*/

int				is_valid_entry(t_data *data, int z, int tot);
/*
** error.c
*/

void			trial(int i);
void			cmd_not_found(t_data *data);

/*
** free.c
*/

void			free_tab(char ***table);
void			free_tab_content(char ***table);

/*
** get_executable.c
*/

int				ex_exec_core(t_data *data, char **paths);
int				ex_exec(t_data *data);

/*
*****************************************************************************************
************************************* EDITLINE ******************************************
*****************************************************************************************
*/

/*
** mouve.c
*/

void			mouve_right(t_var *var);

/*
** print_line.c
*/

void			print_line(t_var *var, char **line, char buf[1000]);

/*
*****************************************************************************************
************************************* INHIBITORS ****************************************
*****************************************************************************************
** quotes.c
*/

int				is_quotes(char *e);
void			put_quote_request(int i);

/*
** backslash.c
*/

int				manage_backslash(t_data *data, char **res, int *i);

/*
*****************************************************************************************
************************************* EXPANSIONS ****************************************
*****************************************************************************************
** expansions_main.c
*/

int				manage_rest(t_data *data, char **res, int *i);
int				expansions(t_data *data);

/*
** expansions_tilde.c
*/

int				go_home(t_data *data, char **res);

/*
** expansions_dollar.c
*/

int				parse_dollar(t_data *data, int *i, char **tmp, char **tmp2);
int				manage_dollar(t_data *data, char **res, int *i);
int				manage_dollar_other(char *value, t_data *data);

/*
** arithmetics.c
*/

int     		is_arithmetics(char *data, int p);
int 			check_if_arithmetics(char *data);

/*
*****************************************************************************************
************************************* BUILTINS ******************************************
*****************************************************************************************
** builtins_main.c
*/

int   			is_builtins(t_data *data);

/*
** builtins_cd.c
*/

void			cd_free(char **tmp, t_data *ndata);
int				b_cd(t_data *data);

/*
** builtins_echo.c
*/

int    			 b_echo(t_data *data);

/*
** builtins_env.c
*/

int				b_env(t_data *data);

/*
** builtins_exit.c
*/

int  		   b_exit(t_data *data);

/*
** builtins_setenv.c
*/

void			add_to_env(t_data *ndata, t_data *data, int i);
int				ft_setline(char *key, char *value, t_data *data);
char			**ft_tabdup(char **table, size_t z);
char			**check_key(char **ret, int i, char *key, char *value);
int				b_setenv(t_data *data);

/*
** builtins_tools.c
*/

char			*tristrjoin(char *s1, char *s2, char *s3);

/*
** builtins_unsetenv.c
*/

void			ft_rmvline(int j, t_data *data);
int				b_unsetenv(t_data *data);

/*
******************************************************************************************
*/

#endif
