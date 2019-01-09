/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_shell.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:37:04 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/09 17:29:49 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_SHELL_H
# define A_SHELL_H

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

void				exit_program(int ret);

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
int					pipe_exception(void);
int					fork_exception(void);
int					file_permission_exception(char *file);
int					fd_exception(char *fd);
int					cmd_not_found_exception(char *cmd);
int					file_not_found_exception(char *file);


int		syntax_exception(char *word, int subcmd);
int		eof_exception(int subcmd);

char				*remove_backslash_before_spechar(char *s);
/*
** var.c
*/

char				*get_var(char *key);
t_var				*newvartab(char **table);

void				refresh_screen(int signum);

/*
** arithmetics.c
*/

int					is_arithmetics(char *data, int p);
int					check_if_arithmetics(char *data);

/*
** init.c
*/

void				init_shell(char **env, int ac, char **av, int debug);
/*
** term.c
*/

void				check_term(t_data *data);

/*
** signals.c
*/

void				signal_list(void);

int					print_lex(t_token *token, char *name);

void				reset_term(t_data *data);
void				init_term(t_data *data);

int					check_if_sigint(t_data *data, char **line);

int					print_lex(t_token *token, char *name);

void				free_tab(char ***table);
void				free_tab_content(char ***table);
void				reset_command(t_data *data);

void				free_ast(t_ast **ast);
void				free_token(t_token **token);
char				*completion(t_data *data, char *line);
char				*complete_from_given_path(char *input);
int					is_a_directory(char *dir, char *file);

int					check_file(char **ret, char *entry, char *file, char *path);
void	reset_subshell(t_data *data);
int		put_exception(int ret, char *prog, char *arg, char *message);

int		ft_is_number(char *s);

void	set_prompt(t_data *data, char *prompt, size_t prompt_len);
void		handle_sigint(t_data *data);

#endif
