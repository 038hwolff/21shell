/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_agregator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:26:12 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/14 15:18:23 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/* 2> : redirige les erreurs dans un fichier (s'il existe déjà, il sera écrasé) ;
** 2>&1 : redirige les erreurs au même endroit et de la même façon que la sortie standard
**          ne fonctionne que sur ksh;
** 2>&- : ferme la sortie indiquee
** >& : est egal a 2>&1, mais ne fonctionne que sur csh ou tcsh
** 1>&2
*/

static int  exec_rederr_err(t_data *data)
{   
    (void)data;
    return (0);
}

static int  exec_rederr_std(t_data *data, char *operator)
{
    (void)data;
    if (ft_strequ(operator, "2>&-") == 1)
    {

        return (1);
    }
    else if (ft_strequ(operator, "2>&1") == 1 || ft_strequ(operator, ">&") == 1)
    {
        return (1);
    }
    return (0);
}

int     main_agregator(t_data *data, t_ast *ast)
{
    (void)data;
    (void)ast;
    char *operator = "lol";
    if (ft_strequ(operator, "2>&1") == 1 || ft_strequ(operator, "2>&-") == 1
        || ft_strequ(operator, ">&") == 1)
        exec_rederr_std(data, operator);
    else if (ft_strequ(operator, "1>&2") == 1)
        exec_rederr_err(data);
    free(data);
    return (0);
}
