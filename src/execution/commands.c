/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:18:01 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/25 11:41:10 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    close_pipe(t_cmd *cmds, int **array_pipe)
{
    int i;
    
    i = 0;
    while ( i < (cmds)->nb_cmds - 1)
    {
        close(array_pipe[i][0]);
        close(array_pipe[i][1]);
        i++;
    }
}
void    pipe_connect(t_cmd *cmd, int **array_pipe)
{
    int i;

    i = 0;
    if (cmd->index != 0)
        dup2(array_pipe[cmd->index - 1][0], 0);
    if (cmd->next)
        dup2(array_pipe[cmd->index][1], 1);
    close_pipe(cmd, array_pipe);
}
int **create_pipe(t_cmd *cmd)
{
    int **array;
    int i;

    i = 0;
    array = 0;
    if (cmd)
    {
        array = malloc ((cmd->nb_cmds - 1) * sizeof(int *));
        while (i < (cmd->nb_cmds - 1))
        {
            array[i] = malloc(sizeof(int) * 2);
            pipe(array[i]);
            i++;
        }
    }
    return (array);
}

int      commands(t_cmd *cmds, char *envp_path)
{
    t_cmd   *curr;
    int     **array_pipe;

    array_pipe = create_pipe(cmds);
    curr = cmds;
    while (curr != NULL)
    {
        curr->id = fork();
        manage_signal(0);
        if (curr->id == 0)
        {
            pipe_connect(curr, array_pipe);
            execute_command(curr, curr->envp, envp_path);
        }
        else if (curr->id < 0)
            printf("Error fork()\n");
        else
            curr = curr->next;
    }
    close_pipe(cmds, array_pipe);
    return (manage_signal(-1), wait_childs(cmds), 1);
}
