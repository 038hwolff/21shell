/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:19:07 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/13 14:18:08 by hben-yah         ###   ########.fr       */
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
# define LINE_UP 71683997260571 /* Maj + up arrow */
# define LINE_DOWN 72783508888347 /* Maj + down arrow */
# define LEFT 4479771
# define RIGHT 4414235
# define HOME 4741915 /* Fn + left arrow */
# define END 4610843 /* Fn + right arrow */
# define SELECT 9082850 /* alt + v */
# define COPY 43458 /* alt + c */
# define PASTE 32975 /* alt + p */
# define CUT 8554722 /* alt + d */
# define CTRLD 4 /* ctrl + d */

/*
** Operators type for lexer tokens
*/

# define WORD					0
# define ASSIGNEMENT_WORD		1

# define IO_NUMBER				2
# define LESS					3
# define GREAT					4
# define DOUBLELESS				5 
# define DOUBLEGREAT			6
# define GREATAND				7

# define PIPE					8
# define DOUBLEAND				9
# define DOUBLEPIPE				10
# define AND					11
# define SEMICOLON				12

# define LESSGREAT				15 // on le fait pas ?
# define LESSAND				16
# define GREATPIPE				17 // clobber on le fait pas
# define DOUBLELESSDASH			18 // on le fait pas ?
# define DOUBLESEMICOLON		19 // ???

# define NEWLINE				20
# define HDOCDELIM				21

/*
** Incomplete command types ("dquote>")
*/

# define COMPLETE			0
# define INC_QUOTE			1
# define INC_DQUOTE			2
# define INC_PIPE			3
# define INC_DPIPE			4
# define INC_DAND			5
# define INC_BKSLASH		6
# define INC_HEREDOC		7

# define PQUOTE 				"quote » "
# define PQUOTE_LEN				8
# define PDQUOTE 				"dquote » "
# define PDQUOTE_LEN			9
# define PBACKSLASH 			"\\ » "
# define PBACKSLASH_LEN			4
# define PHEREDOC 				"heredoc » "
# define PHEREDOC_LEN			10
# define PDEFAULT				"» "
# define PDEFAULT_LEN			2

#endif

