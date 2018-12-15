/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:49:42 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/15 13:12:24 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int     is_builtins(t_data *data, t_ast *ast)
{
    if (data && ast)
    {
        if (ft_strcmp(ast->left->token->val, "exit") == 0)
            b_exit(data);
        else if (ft_strcmp(ast->left->token->val, "cd") == 0)
            b_cd(data);
        else if (ft_strcmp(ast->left->token->val, "echo") == 0)
            b_echo(data);
        else if (ft_strcmp(ast->left->token->val, "env") == 0)
            b_env(data);
        else if (ft_strcmp(ast->left->token->val, "setenv") == 0)
            b_setenv(data);
        else if (ft_strcmp(ast->left->token->val, "unsetenv") == 0)
            b_unsetenv(data);
        else
            return (0);
        return (1);
    }   
    return (0);
}
