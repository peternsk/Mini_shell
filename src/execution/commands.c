/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:18:01 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/26 14:36:06 by mnshimiy         ###   ########.fr       */
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

int **create_pipe(t_cmd *cmd)
{
    int **array;
    int i;

    i = 0;
    array = 0;
    if (cmd && cmd->nb_cmds  > 1)
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

void see_pipe_has_been_copy(t_cmd *pipe)
{
    t_cmd *curr;

    curr = pipe;
    while (curr != NULL)
    {
        if (curr->files)
            printf("seeeee pipe  copy%d\n", curr->files->manage_fd);
        curr = curr->next;
    }
}

void replace_files_des(t_cmd *curr)
{
    if (curr && curr->files)
    {
        if (curr->files->type == here_doc)
        {
            printf("close --fd %d\n", curr->files->manage_fd);
            dup2(curr->files->manage_fd, 0);
            close(curr->files->manage_fd);
        }
    }
}

int      commands(t_cmd *cmds, char *envp_path)
{
    t_cmd   *curr;
    int     **array_pipe;

    array_pipe = create_pipe(cmds);
    which_files(cmds);
    curr = cmds;
    while (curr != NULL)
    {
        curr->id = fork();
        manage_signal(0);
        if (curr->id == 0)
        {
            execute_command(curr, envp_path, array_pipe);
        }
        else if (curr->id < 0)
            printf("Error fork()\n");
        else
            curr = curr->next;
    }
    close_pipe(cmds, array_pipe);
    return (manage_signal(-1), wait_childs(cmds), 1);
}
