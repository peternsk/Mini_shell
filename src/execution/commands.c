/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:18:01 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/23 23:08:48 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int _childs_fd(int fd[], int last_fd, t_cmd *curr, t_cmd *cmds)
{
    pipe(fd);
    if (curr->index == 0)
    {
        last_fd = fd[0];
        fd[0] = 0;
    }
    else
    {
        last_fd ^= fd[0];
        fd[0] ^= last_fd;
        last_fd ^= fd[0];
    }
    if (curr->index == cmds->nb_cmds - 1)
    {
        // Don't change put in next pipe if there an > or >>
        close(fd[1]);
        fd[1] = 1;
    }
    return (last_fd);
}

int expan_child(int fd[], t_cmd *curr, char *envp_path)
{
    if (fd[0] != 0)
    {
        dup2(fd[0], 0);
        close(fd[0]);
    }
    if (fd[1] != 1)
    {
        // pas sur check si c'est un file ou bien redirection de file et append file 
        if (!curr->files)
            dup2(fd[1], 1);
        close(fd[1]);
    }
    if (execute_command(curr, curr->envp, envp_path) == -1)
        return (-1);
    return (1);
}

void _curren_fd(int fd[], int last_fd, t_cmd *cmds)
{
    if (cmds->index != 0)
        close(fd[0]);
    if (cmds->index != cmds->nb_cmds -1)
        close(fd[1]);
    else 
        close(last_fd);
}
// free id_childs
int      commands(t_cmd *cmds, char *envp_path)
{
    t_cmd   *curr;
    int     fd[2];
    int     last_fd;
    
    curr = cmds;
    while (curr != NULL)
    {
        last_fd = _childs_fd(fd, last_fd, curr, cmds);
        curr->id = fork();
        manage_signal(0);
        if (curr->id == 0)
        {
            if (expan_child(fd, curr, envp_path) == -1)
                return (-1);
        }
        else if (curr->id < 0)
            printf("Error fork()\n");
        else
        {
            _curren_fd(fd, last_fd, curr);
            curr = curr->next;
        } 
    }
    return (manage_signal(-1), wait_childs(cmds), 1);
}
