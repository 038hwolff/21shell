/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:46:54 by hben-yah          #+#    #+#             */
/*   Updated: 2018/10/25 17:17:41 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

/*
** Headers
*/


/*
** Bonus headers
*/

# include <dirent.h>

/*
** Libft
*/

# include "../libft/includes/libft.h"
# include "termios.h"
# include "term.h"

/*
** Typedef / Structs
*/

typedef void	(*t_sighandler)(int);

typedef struct	s_sh_data
{
	char		**env;
	char		**args;
	char		*input;
	int			childpid;
}				t_sh_data;

typedef struct	s_built
{
	char		**av;
	int			ac;
	t_sh_data	*env;
}				t_built;

/*
** Prototypes
*/



/*
** Globals
*/

t_sh_data		g_sh_data;

int				main(int ac, char **av, char **env);

/*
** BUILTINS
*/

int    			is_builtins(t_built *built);
int     		b_exit();
int     		b_echo(t_built *built);

#endif
