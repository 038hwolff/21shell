/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_builtins.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:23:22 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/30 21:18:57 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_BUILTINS_H
# define G_BUILTINS_H

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

int					b_env(t_data *data, char **arg);

/*
** builtins_exit.c
*/

int					b_exit(t_data *data, char **arg);

/*
** builtins_setenv.c
*/

void				add_to_env(char ***nenv, char **arg, int i);
int					ft_setline(char *key, char *value, char ***env);
char				**ft_tabdup(char **table, size_t z);
char				**check_key(char **ret, int i, char *key, char *value);
int		b_setenv(t_data *data, char **arg);

/*
** builtins_tools.c
*/

char				*tristrjoin(char *s1, char *s2, char *s3);

/*
** builtins_unsetenv.c
*/

void				ft_rmvline(int j, t_data *data);
int					b_unsetenv(t_data *data, char **arg);

void				unset_one(char ***vars, char *arg, size_t len);

int					b_unset(t_data *data, char **args);
int					b_export(t_data *data, char **arg);
int					b_set(t_data *data, char **arg);


#endif
