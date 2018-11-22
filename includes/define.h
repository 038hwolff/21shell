/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:19:07 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/21 15:39:11 by hben-yah         ###   ########.fr       */
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


# define ENTER 10
# define SPACE 32
# define TAB 9
# define SUPP 127
# define UP 4283163
# define DOWN 4348699
# define UP_FN 2117425947
# define DOWN_FN 2117491483
# define LEFT 4479771
# define RIGHT 4414235
# define HOME 4741915 /* Fn + left arrow */
# define END 4610843 /* Fn + right arrow */

/*
** Operators type for lexer tokens
*/

# define DOUBLELESSDASH			0 // on le fait pas ?
# define DOUBLELESS				1 
# define DOUBLEGREAT			2
# define LESSGREAT				3 // on le fait pas ?
# define LESSAND				4
# define GREATAND				5
# define GREATPIPE				6 // clobber on le fait pas
# define DOUBLEAND				7
# define DOUBLEPIPE				8
# define DOUBLESEMICOLON		9 // ???
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

