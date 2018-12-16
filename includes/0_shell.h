/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_shell.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:37:04 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/16 18:49:14 by hben-yah         ###   ########.fr       */
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

/*
** void				display_prompt(void);
*/

/*
** exception.c
*/

void				*try_m(void *ptr);
void				term_exception(char *message);
void				tent_exception(char *ent);
int					syntax_exception(char *word);
int					pipe_exception(void);
int					fork_exception(void);
int					file_permission_exception(char *file);
int					fd_exception(char *fd);

/*
** var.c
*/

char *get_var(char *key);
t_var			*newvartab(char **table);


void				refresh_screen(int signum);

/*
** arithmetics.c
*/

int					is_arithmetics(char *data, int p);
int					check_if_arithmetics(char *data);

/*
** init.c
*/

void				init_shell(char **env);
/*
** term.c
*/

void				check_term(t_data *data);

/*
** signals.c
*/

void				init_sig();

int 	            print_lex(t_token *token, char *name);

void	            reset_term(t_data *data);
void	            reset_shell(t_data *data);
void            	init_term(t_data *data);

int					check_if_sigint(t_data *data, char **line);
int					eof_exception(void);

int			    	print_lex(t_token *token, char *name);

void				free_tab(char ***table);
void				free_tab_content(char ***table);

#endif
