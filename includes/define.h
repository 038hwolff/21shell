/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:19:07 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/15 17:05:53 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/*
** Defines
*/

# define ERR_PREFIX "21sh: "
# define SHPRINT 1

/*
** Line editor keys
**
** LINE_UP      Maj + up arrow
** LINE_DOWN    Maj + down arrow
** HOME         Fn + left arrow
** END          Fn + right arrow
** SELECT       alt + v
** COPY         alt + c
** PASTE        alt + p
** CUT          alt + d
** CTRLD        ctrl + d
*/

# define ENTER 10
# define SPACE 32
# define TAB 9
# define SUPP 127
# define UP 4283163
# define DOWN 4348699
# define UP_FN 2117425947
# define DOWN_FN 2117491483
# define LINE_UP 71683997260571
# define LINE_DOWN 72783508888347
# define LEFT 4479771
# define RIGHT 4414235
# define HOME 4741915
# define END 4610843
# define SELECT 9082850
# define COPY 43458
# define PASTE 32975
# define CUT 8554722
# define CTRLD 4

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

# define LESSGREAT				15
# define LESSAND				16
# define GREATPIPE				17
# define DOUBLELESSDASH			18
# define DOUBLESEMICOLON		19

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
