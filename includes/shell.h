/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:46:54 by hben-yah          #+#    #+#             */
/*   Updated: 2018/09/24 17:12:55 by hben-yah         ###   ########.fr       */
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

# include "libft.h"
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

/*
** Prototypes
*/



/*
** Globals
*/

t_sh_data		g_sh_data;

#endif
