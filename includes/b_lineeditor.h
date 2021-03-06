/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_lineeditor.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:26:21 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/23 22:39:57 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_LINEEDITOR_H
# define B_LINEEDITOR_H

/*
** loop.c
*/

void			display_prompt(t_edl *edl);

/*
** mouve.c
*/

void			mouve_right(t_edl *edl);
void			mouve_left(t_edl *edl);
void			prev_word(t_edl *edl);
void			next_word(t_edl *edl, size_t len);

/*
** print_line.c
*/

void			print_line(t_data *data, unsigned long key);

/*
** term.c
*/

char			*ft_termcaps(t_edl *edl, unsigned long key, t_hist *hist);
void			line_moves(t_edl *edl, unsigned long key);

/*
** history.c
*/

char			**add_history(char *line, t_hist *hist);
void			history_umove(t_edl *edl, t_hist *hist);
void			history_dmove(t_edl *edl, t_hist *hist);

/*
** command_reader.c
*/

void			read_command_line();
int				len_line(t_edl *edl);

void			read_line();
int				ft_enter(t_edl *edl);

t_edl			*setup_edl(t_edl *edl);

void			read_additional_line(char **line);
/*
** setup.c
*/

t_hist			*setup_hist(t_hist *hist);

/*
** select_mode.c
*/

void			select_mode(t_edl *edl, unsigned long key);

/*
** copy_paste.c
*/

void			copy_high(t_edl *edl, t_hist *hist);
char			*paste_char(t_edl *edl, t_hist *hist);
void			clear_line(t_edl *edl, char *n_line);

/*
** cut_high.c
*/

char			*cut_high(t_edl *edl, t_hist *hist);

/*
** control_keys.c
*/

char			*control_d(t_data *data);
int				check_eof(t_data *data);

/*
** supp_char.c
*/

char			*supp_char(t_edl *edl, unsigned long key);
char			*insert_char(unsigned long key, t_edl *edl);
char			*complete_word(t_data *data);
int				get_cursor_line(t_edl *edl, int i, char *s);
void			move_cursor_to_index(t_edl *edl);
int				get_current_line_len(t_edl *edl, int i);
void			erase_line(t_data *data);

#endif
