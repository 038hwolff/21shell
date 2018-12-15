/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:03:53 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/15 14:08:45 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

/*
** Headers
*/

# include <stdio.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <fcntl.h>
# include <signal.h>

/*
** Bonus headers
*/

# include <dirent.h>

/*
** Libs
*/

# include "libft.h"
# include <term.h>

/*
** Defines
*/

# include "define.h"

/*
** Typedef / Structs
*/

# include "struct.h"

/*
** Headers 21sh
*/

# include "0_shell.h"
# include "1_lineeditor.h"
# include "2_lexer.h"
# include "3_parser.h"
# include "4_astbuilder.h"
# include "5_executor.h"
# include "6_builtins.h"

/*
** Globals
*/

t_data				g_sh_data;
int					g_reset_entry;

#endif
