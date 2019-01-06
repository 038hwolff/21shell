/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:19:07 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/06 19:41:03 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H



// macro de debug, à virer au moment de mettre à la norme
# define M1 ft_printf("\nMARQUEUR 1\n");
# define M2 ft_printf("\nMARQUEUR 2\n");
# define M3 ft_printf("\nMARQUEUR 3\n");
# define M4 ft_printf("\nMARQUEUR 4\n");
# define M5 ft_printf("\nMARQUEUR 5\n");
# define Ms(x) ft_printf("\n%s\n", x);
# define Md(x) ft_printf("\n%d\n", x);
// a virer
//a virer


/*
** Defines
*/

# define SH_NAME "21sh"
# define DEFAULT_TERM "xterm-256color"
/*
**	Flag utilise lors de l'expansion des variables
*/

# define STR_FORMAT 0
# define NBR_FORMAT 1

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
# define TABU 9
# define SUPP 127
# define DELETE 2117294875
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
# define SELECT 10127586
# define COPY 42947
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
# define LESSAND				7
# define GREATAND				8

/*
** Control Operators
*/

# define PIPE					9
# define CLOSED_PAR				10
# define OPEN_PAR				11
# define AND					12
# define DOUBLEPIPE				13
# define DOUBLEAND				14
# define SEMICOLON				15
# define NEWLINE				16

/*
** Unsupported operators (syntax error)
*/

# define LESSGREAT				20
# define GREATPIPE				22
# define DOUBLELESSDASH			23
# define DOUBLESEMICOLON		24

/*
** Heredoc end of here
*/

# define HDOCDELIM				31

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
# define INC_PARENT			8
# define INC_BKQUOTE		9

# define PQUOTE 				"quote » "
# define PQUOTE_LEN				8
# define PDQUOTE 				"dquote » "
# define PDQUOTE_LEN			9
# define PBQUOTE 				"` » "
# define PBQUOTE_LEN			4
# define PBACKSLASH 			"\\ » "
# define PBACKSLASH_LEN			4
# define PHEREDOC 				"heredoc » "
# define PHEREDOC_LEN			10
# define PPARENT 				"( » "
# define PPARENT_LEN			4
# define PDEFAULT				"» "
# define PDEFAULT_LEN			2

/*
** Return codes
*/

# define RET_OK		            0
# define RET_ERROR	            1
# define RET_MAJ_ERROR          2
# define RET_PERM_DENIED		126
# define RET_NOT_FOUND		    127

#endif
