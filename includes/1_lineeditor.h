/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_lineeditor.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:26:21 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/19 16:49:40 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINEEDITOR_H
# define LINEEDITOR_H

/*
** mouve.c
*/

void				mouve_right(t_var *var);
void				mouve_left(t_var *var);

/*
** print_line.c
*/

void				print_line(t_var *var, char **line, char buf[1000]);

/*
** term.c
*/

char				*ft_termcaps(t_var *var, char *line, char *buf);

/*
** history.c
*/

char				**add_history(t_var *var, char *line);
char				*history_umove(t_var *var);
char				*history_dmove(t_var *var);

/*
** command_reader.c
*/

void	read_command_line(void);

int	len_line(t_var *var);

void	loop(void);
int	ft_enter(char *line, t_var *var);
t_var	*setup_var(t_var *var);


#endif
