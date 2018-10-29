/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:46:54 by hben-yah          #+#    #+#             */
/*   Updated: 2018/10/29 20:44:29 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

/*
** Headers
*/

# include <termios.h>

/*
** Bonus headers
*/

# include <dirent.h>

/*
** Libft
*/

# include "libft.h"
# include <term.h>

/*
** Other Shell parts Headers (ex : builtin.h, etc.)
*/

/*
** Defines
*/

/*
** Keys
*/

/*
** Typedef / Structs
*/

typedef void	(*t_sighandler)(int);

typedef struct	s_data
{
	char		**env;
	char		**args;
	char		*input;
	int			childpid;
	short		on;
}				t_data;

typedef struct	s_built
{
	char		**av;
	int			ac;
	t_data		*env;
}				t_built;

/*
** Globals
*/

t_data			g_sh_data;

/*
** Prototypes
*/

/*
** shell.c
*/

int				main(int ac, char **av, char **env);

/*
** BUILTINS
*/

int    			is_builtins(t_built *built);
int     		b_exit(void);
int     		b_echo(t_built *built);

#endif
