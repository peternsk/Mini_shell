
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
        array = malloc_and_add((cmd->nb_cmds - 1) * sizeof(int *));
        while (i < (cmd->nb_cmds - 1))
        {
            array[i] = malloc_and_add(sizeof(int) * 2);
            pipe(array[i]);
            i++;
        }
    }
    return (array);
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
