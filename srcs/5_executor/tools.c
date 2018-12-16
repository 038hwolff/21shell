/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:29:44 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/15 23:08:15 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int     count_word(t_token *token)
{
    int i;

    i = 0;
    while (token)
    {
        i++;
        token = token->next;
    }
    return (i);
}

char    **token_to_tab(t_ast *ast)
{
    char    **table;
    char    **p;
    int     nbword;
   
    nbword = count_word(ast->token);
    try_m((table = (char **)ft_memalloc(sizeof(char *) * (nbword + 1))));
    p = table;
    while (ast)
    {
        try_m((*p = ft_strdup(ast->token->val)));
        ast = ast->right;
        ++p;
    }
    return (table);
}
