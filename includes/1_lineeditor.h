/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_lineeditor.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:26:21 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/03 21:54:16 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINEEDITOR_H
# define LINEEDITOR_H

/*
** loop.c
*/

void			display_prompt(char *prompt);

/*
** mouve.c
*/

void			mouve_right(t_edl *edl);
void			mouve_left(t_edl *edl);
void			prev_word(t_edl *edl, char *line);
void			next_word(t_edl *edl, char *line, size_t len);

/*
** print_line.c
*/

void			print_line(t_edl *edl, char **line, unsigned long key);

/*
** term.c
*/

char			*ft_termcaps(t_edl *edl, char *line, unsigned long key, t_hist *hist);

/*
** history.c
*/

char			**add_history(char *line, t_hist *hist);
void			history_umove(t_edl *edl, char **line, t_hist *hist);
void			history_dmove(t_edl *edl, char **line, t_hist *hist);

/*
** command_reader.c
*/

void	read_command_line();
int	len_line(t_edl *edl);
void	read_line();
int	ft_enter(char *line, t_edl *edl);
t_edl	*setup_edl(t_edl *edl);
void	setup_env(int ac, char **av, t_env *env);

void	read_additional_line(char **line);
/*
** setup.c
*/

t_hist *setup_hist(t_hist *hist);

/*
** select_mode.c
*/

void	select_mode(t_edl *edl, unsigned long key);

/*
** copy_paste.c
*/

void	copy_high(t_edl *edl, t_hist *hist, char *line);
char	*paste_char(t_edl *edl, t_hist *hist, char *line);

#endif
