/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_shell.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:37:04 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/13 13:00:48 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_SHELL_H
# define PROTO_SHELL_H

/*
** shell.c
*/

t_data				*get_data(void);
int					shell(int ac, char **av, char **env);
int					sh_putchar(int c);

/*
** reset.c
*/

void				reset_shell(t_data *data);

/*
** free.c
*/

void				free_data(t_data *data);

/*
** exit.c
*/

void				exit_program(char *message);

/*
** prompt.c
*/

/*void				display_prompt(void);*/

/*
** exception.c
*/

void			*try_m(void *ptr);
void			term_exception(char *message);
void			tent_exception(char *ent);
int				syntax_exception(char *word);

/*
** var.c
*/

char *get_variable(char *key);
t_variable			*newvartab(char **table);

void				signal_handler(void (*restart)(int));
void				refresh_screen(int signum);

int					exec_pipes(t_data *data, int nb);

int     			exec_heredoc(t_data *data);

int     			main_redirec(t_data *data, char *raft);

/*
** arithmetics.c
*/

int					is_arithmetics(char *data, int p);
int					check_if_arithmetics(char *data);

/*
** init.c
*/

void	init_shell(char **env);
/*
** term.c
*/

void check_term(t_data *data);

/*
** signals.c
*/

void	init_sig();

int		check_if_sigint(t_data *data, char **line);
int		eof_exception(void);

void 	print_lex(t_token *token, char *name);


# endif
