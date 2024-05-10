/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:15:59 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/09 14:31:14 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_builtin(char *s)
{
    if (ft_strcmp(s, "cd") == true)
        return (8);
    if (ft_strcmp(s, "echo") == true)
        return (8);
    if (ft_strcmp(s, "pwd") == true)
        return (8);
    if (ft_strcmp(s, "export") == true)
        return (8);
    if (ft_strcmp(s, "unset") == true)
        return (8);
    if (ft_strcmp(s, "env") == true)
        return (8);
    if (ft_strcmp(s, "exit") == true)
        return (8);
    return (-1);
}

int is_files(char *s)
{
    if (ft_strcmp(s, "<<") == true)
        return (here_doc);
    if (ft_strcmp(s, ">>")== true)
        return (apnd_op_redir);
    if (ft_strcmp(s, ">") == true)
        return (out_p_redir);
    if (ft_strcmp(s, "<") == true)
        return (in_p_redir);
    return (-1);
}

int type_cmds(char *s)
{
    int _res;
    if (!s)
        return (-1);
    _res = is_builtin(s);
    if (_res > -1)
        return (_res);
    _res = is_files(s);
    if (_res > -1)
        return (_res);
    return (command);
}