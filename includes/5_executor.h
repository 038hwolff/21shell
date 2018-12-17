
#ifndef EXECUTOR_H
# define EXECUTOR_H

/*
** expansions_main.c
*/

int					manage_rest(t_data *data, char **res, int *i);
int					expansions(t_data *data);

/*
** expansions_tilde.c
*/

int					go_home(t_data *data, char **res);

/*
** expansions_dollar.c
*/

int					parse_dollar(t_data *data, int *i, char **tmp, char **tmp2);
int					manage_dollar(t_data *data, char **res, int *i);
int					manage_dollar_other(char *value, t_data *data);

/*
** executor.c
*/

int					exec_redirect(t_data *data, t_ast *ast, int rafter);
int					exec_back_redirect(t_data *data, t_ast *ast);
int					and_or(t_data *data, t_ast *ast);

int					set_local_var(t_data *data, t_ast *ast);
int					main_agregator(t_data *data, t_ast *ast);
int					exec_pipes(t_data *data, t_ast *ast);

int					main_redirec(t_data *data, char *raft);

int					execute_conditions(t_data *data, t_ast *ast);
int					execute_semicolon(t_data *data, t_ast *ast);

char				**get_path(char **env, char **arg);
int					exec_cmd_line(t_data *data, t_ast *ast);
int					ex_exec(char **env, char **arg);
int					ex_exec_core(char **env, char **table, char **paths);
char    			**token_to_tab(t_ast *ast);

int					exec_heredoc(t_data *data, t_ast *ast);


/*
**	Expansion
*/

void				expansion(t_data *data, t_token *token);
int					exp_tilde(char **str, t_data *data);
void				exp_vars(char **str, t_data *data);
char				*exp_vars_get(char *str, t_data *data);
char				*exp_sub_param(t_varsexp *exp, char *key,
						char *val, char *word);
char				*exp_sub_word(t_varsexp *exp, char *key,
						char *val, char *word);
char				*exp_sub_null(t_varsexp *exp, char *key,
						char *val, char *word);
char				*exp_sub_error(t_varsexp *exp, char *key,
						char *val, char *word);
char				*exp_assign(t_varsexp *exp, char *key,
						char *val, char *word);
char				*exp_unhandle(t_varsexp *exp, char *key,
						char *val, char *word);
void				exp_goto_next_quote(char **str);

/*
**	Environment tools
*/

char				*env_get(char **arr, char *key);
int					env_set(char ***arr, char *key, char *value, char flag);
char				**sh_env_get_ref(char **arr, char *key);

int					exp_quotes(char **str);

#endif
