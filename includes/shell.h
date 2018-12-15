/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:03:53 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/22 21:02:44 by hben-yah         ###   ########.fr       */
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
** Globals
*/

t_data				g_sh_data;
int					g_reset_entry;

/* ************************************************************************** */
/*                  SHELL													  */
/* ************************************************************************** */

# include "0_shell.h"

/* ************************************************************************** */
/*                  LINEEDITOR												  */
/* ************************************************************************** */

# include "1_lineeditor.h"

/* ************************************************************************** */
/*                  LEXER													  */
/* ************************************************************************** */

# include "2_lexer.h"

/* ************************************************************************** */
/*                  PARSER													  */
/* ************************************************************************** */

# include "3_parser.h"

/* ************************************************************************** */
/*                  ASTBUILDER												  */
/* ************************************************************************** */

# include "4_astbuilder.h"

/* ************************************************************************** */
/*                  EXECUTOR												  */
/* ************************************************************************** */

# include "5_executor.h"

/* ************************************************************************** */
/*                  BUILTINS												  */
/* ************************************************************************** */

# include "6_builtins.h"

#endif
