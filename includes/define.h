/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:19:07 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/18 18:15:34 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/*
** Defines
*/

# define ERR_PREFIX "21sh: "

/*
** Line editor keys
*/

# define ENTER ((buf[0] == 10 && buf[1] == 0 )|| (buf[0] == 13 && buf[1] == 0))
# define SUPP (buf[0] == 127 && buf[1] == 0)
# define DEL (buf[0] == 27 && buf[1] == 91 && buf[2] == 51 && buf[3] == 126)
# define HAUT (buf[0] == 27 && buf[1] == 91 && buf[2] == 65)
# define BAS (buf[0] == 27 && buf[1] == 91 && buf[2] == 66)
# define GAUCHE (buf[0] == 27 && buf[1] == 91 && buf[2] == 68)
# define DROITE (buf[0] == 27 && buf[1] == 91 && buf[2] == 67)

/*
** Operators type for lexer tokens
*/

# define DOUBLELESSDASH			0
# define DOUBLELESS				1
# define GREATGREAT				2
# define LESSGREAT				3
# define LESSAND				4
# define GREATAND				5
# define GREATPIPE				6
# define DOUBLEAND				7
# define DOUBLEPIPE				8
# define DOUBLESEMICOLON		9
# define PIPE					10
# define AND					11
# define SEMICOLON				12
# define LESS					13
# define GREAT					14
# define NEWLINE				20
# define IO_NUMBER				21
# define WORD					30
# define ASSIGNEMENT_WORD		31
# define NAME					32

/*
** Missing characters and prompt types ("dquote>")
*/

# define MISSINGQUOTE			1
# define MISSINGDQUOTE			2
# define MISSINGPIPE			3
# define MISSINGDPIPE			4
# define MISSINGDAND			5
# define MISSINGBKSLASH			6

# define PQUOTE 				"quote> "
# define PDQUOTE 				"dquote> "
# define PBACKSLASH 			"> "
# define PDOUBLEAND 			"> "
# define PDDOUBLEPIPE 			"> "
# define PPIPE 					"> "

#endif

