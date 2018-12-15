/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_builtins.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:23:22 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/15 23:13:21 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

/*
** builtins_main.c
*/

int					is_builtins(t_data *data, char **arg);

/*
** builtins_cd.c
*/

void				cd_free(char **tmp, t_data *ndata);
int					b_cd(t_data *data, char **env, char **arg);

/*
** builtins_echo.c
*/

int					b_echo(char **arg);

/*
** builtins_env.c
*/

int					b_env(char **env, char **arg);

/*
** builtins_exit.c
*/

void				b_exit();

/*
** builtins_setenv.c
*/

void				add_to_env(char **nenv, char **arg, int i);
int					ft_setline(char *key, char *value, char ***env);
char				**ft_tabdup(char **table, size_t z);
char				**check_key(char **ret, int i, char *key, char *value);
int					b_setenv(char ***env, char **arg);

/*
** builtins_tools.c
*/

char				*tristrjoin(char *s1, char *s2, char *s3);

/*
** builtins_unsetenv.c
*/

void				ft_rmvline(int j, t_data *data);
int					b_unsetenv(t_data *data, char **arg);

#endif
