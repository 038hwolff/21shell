/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_builtins.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:23:22 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/18 15:45:59 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

/*
** builtins_main.c
*/

int					is_builtins(t_data *data);

/*
** builtins_cd.c
*/

void				cd_free(char **tmp, t_data *ndata);
int					b_cd(t_data *data);

/*
** builtins_echo.c
*/

int					b_echo(t_data *data);

/*
** builtins_env.c
*/

int					b_env(t_data *data);

/*
** builtins_exit.c
*/

int					b_exit(t_data *data);

/*
** builtins_setenv.c
*/

void				add_to_env(t_data *ndata, t_data *data, int i);
int					ft_setline(char *key, char *value, t_data *data);
char				**ft_tabdup(char **table, size_t z);
char				**check_key(char **ret, int i, char *key, char *value);
int					b_setenv(t_data *data);

/*
** builtins_tools.c
*/

char				*tristrjoin(char *s1, char *s2, char *s3);

/*
** builtins_unsetenv.c
*/

void				ft_rmvline(int j, t_data *data);
int					b_unsetenv(t_data *data);

#endif
