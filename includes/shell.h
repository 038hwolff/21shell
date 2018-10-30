/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:46:54 by hben-yah          #+#    #+#             */
/*   Updated: 2018/10/30 17:06:59 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

/*
** Headers
*/


/*
** Bonus headers
*/

# include <dirent.h>

/*
** Libft
*/

# include "../libft/includes/libft.h"
# include "termios.h"
# include "term.h"

/*
** Typedef / Structs
*/

typedef void	(*t_sighandler)(int);

typedef struct	s_data
{
	char		**env;
	char		**args;
	char		*entry;
	int			childpid;
}				t_data;

typedef struct	s_built
{
	char		**av;
	int			ac;
	t_data		*env;
}				t_built;

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
** Prototypes
*/

void			handle_signal(int signal);
char			**get_path(t_data *data);
char			**split_for_display(char *entry);
int				global_parse(t_data *data);
int				main(int ac, char **av, char **env);

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

int  		   b_exit();

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
