/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_executor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:19:52 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/14 17:24:51 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int 	            execute(t_data *data, t_ast *ast);
int                 exec_redirect(t_data *data, t_ast *ast, int rafter);
int	                exec_back_redirect(t_data *data, t_ast *ast);
int		            and_or(t_data *data, t_ast *ast);

int					ex_exec(t_data *data, t_ast *ast);
int					set_local_var(t_data *data, t_ast *ast);

int				    main_agregator(t_data *data, t_ast *ast);
int             	exec_pipes(t_data *data, t_ast *ast);

int     			exec_heredoc(t_data *data);

int     			main_redirec(t_data *data, char *raft);

int					execute_conditions(t_data *data, t_ast *ast);
int					execute_semicolon(t_data *data, t_ast *ast);

char				**get_path(t_data *data);

#endif
