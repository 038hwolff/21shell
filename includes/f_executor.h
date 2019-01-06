/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_executor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:27:53 by hwolff            #+#    #+#             */
/*   Updated: 2019/01/06 15:48:58 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_EXECUTOR_H
# define F_EXECUTOR_H

/*
** executor.c
*/

int					exec_redirect(t_data *data, t_ast *ast, int rafter);
int					exec_redirect2(t_data *data, t_ast *ast);
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
char				**token_to_tab(t_ast *ast);

int					exec_heredoc(t_data *data, t_ast *ast);

/*
**	Expansion
*/

void				expansion(t_data *data, t_token *token);
int					exp_tilde(char **str, t_data *data);
void				exp_vars(char **str, t_data *data, int heredoc);
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

char				*var_get_val(char **arr, char *key);
int					var_set(char ***vars, char *key, char *value);
char				**var_get_ptr(char **arr, char *key);

int					var_set_line(char ***vars, char *line);
void				var_unset(char ***vars, char *key);


int					exec_assignement(t_data *data, t_ast *ast);

int					exp_quotes(char **str);
char			exec_subcmd(t_data *data, t_ast *ast);
void			exp_substit_cmd(char **str, t_data *data);
int		subshell(int ac, char **av, char **env);

int				main_back_agregator(t_data *data, t_ast *ast);


#endif
