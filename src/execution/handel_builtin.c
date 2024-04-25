/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 01:48:26 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/25 18:23:31 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// 1 cd 
// 2 echo 
// 3 pwd 
// 4 export 
// 5 unset 
// 6 env 
// 7 exit 

int which_built(t_cmd *built)
{
    if (ft_strncmp(built->cmd_name, "cd", ft_strlen("cd")) == 0)
        return (1);
    if (ft_strncmp(built->cmd_name, "echo", ft_strlen("echo")) == 0)
        return (2);
     if (ft_strncmp(built->cmd_name, "pwd", ft_strlen("pwd")) == 0)
        return (3);
     if (ft_strncmp(built->cmd_name, "export", ft_strlen("export")) == 0)
        return (4);
     if (ft_strncmp(built->cmd_name, "unset", ft_strlen("unset")) == 0)
        return (5);
    if (ft_strncmp(built->cmd_name, "env", ft_strlen("env")) == 0)
        return (6);
    if (ft_strncmp(built->cmd_name, "exit", ft_strlen("exit")) == 0)
        return (7);
    return (-1);
}
// void    evecv_built(t_cmd *built, int _w)
// {
//     (void)built;
//     // if (_w == 1)
//     //     // cd
//     // if (_w == 2)
//     //     // echo
//     // if (_w == 3)
//     //     // pwd
//     // if (_w == 4)
//     //     // export
//     // if (_w == 5)
//     //     // unset
//     // if (_w == 6)
//     //     // env
//     // if (_w == 7)
//     //     // exit
// }
// int handel_builtin(t_cmd *cmd)
// {
//     int _res;
    
//     _res = -1;
//     if (cmd)
//     {
//         _res = which_built(cmd);
//         if (_res > -1)    
//             evecv_built(cmd, _res);
//     }
//     return (_res);
// }