/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:15:12 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/23 01:47:53 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// check the cmd type 
// if is 
int    single_command(t_cmd *cmd, char **envp, char *envp_path)
{
    if (cmd)
    {
        if (cmd->type == 8)
            handel_builtin(cmd);
        else
        {
            cmd->id = fork();
            if (cmd->id == 0)
            {
                // is on doit change le stdint ou le out ?
                if (execute_command(cmd, envp, envp_path) == -1)
                    return (-1);
            }
            else if (cmd->id < 0)
                printf("------Error fork()\n");
            wait_childs(cmd);
            return (1);
        }
    }
    return (-1);   
}

void fake_2()
{
    
}