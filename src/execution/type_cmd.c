/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:15:59 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/08 18:44:40 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_builtin(const char *s)
{
    if (ft_strncmp(s, "cd", ft_strlen(s)) == 0)
        return (8);
    if (ft_strncmp(s, "echo", ft_strlen(s)) == 0)
        return (8);
    if (ft_strncmp(s, "pwd", ft_strlen(s)) == 0)
        return (8);
    if (ft_strncmp(s, "export", ft_strlen(s)) == 0)
        return (8);
    if (ft_strncmp(s, "unset", ft_strlen(s)) == 0)
        return (8);
    if (ft_strncmp(s, "env", ft_strlen(s)) == 0)
        return (8);
    if (ft_strncmp(s, "exit", ft_strlen(s)) == 0)
        return (8);
    return (-1);
}

int is_files(const char *s)
{
    if (ft_strncmp(s, "<<", ft_strlen(s)) == 0)
        return (here_doc);
    if (ft_strncmp(s, ">>", ft_strlen(s)) == 0)
        return (apnd_op_redir);
    if (ft_strncmp(s, ">", ft_strlen(s)) == 0)
        return (out_p_redir);
    if (ft_strncmp(s, "<", ft_strlen(s)) == 0)
        return (in_p_redir);
    return (-1);
}

int type_cmds(const char *s)
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