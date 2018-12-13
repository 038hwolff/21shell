/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_executor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:19:52 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/13 18:21:26 by hwolff           ###   ########.fr       */
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

int 	            execute(t_data *data, t_arg *ast);
int                 exec_redirect(t_data *data, t_ast *ast, int rafter);
int	                exec_back_redirect(t_data *data, t_ast *ast);

#endif
