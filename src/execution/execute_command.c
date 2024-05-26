#include "minishell.h"

// ajouter la function qui dis le bon put error 


void    pipe_connect(t_cmd *current, int **array_pipe)
{
    int i;

    i = 0;
    if (current->index != 0)
    {
        dup2(array_pipe[current->index - 1][0], 0);
    }
    if (current->next)
    {
        dup2(array_pipe[current->index][1], 1);
    }
    while ( i < (current)->nb_cmds - 1)
    {
        close(array_pipe[i][0]);
        close(array_pipe[i][1]);
        i++;
    }
}
int execute_command(t_cmd *current, char *envp_path, int **array_pipe)
{
    char	*cmd_path;

    if (!current)
        return (printf("current is NULL"), -1);
    pipe_connect(current, array_pipe);
    current->is_file_on = is_files_valide(current);
    if (current->nb_cmds > 1 && current->nb_pipes > 0 && current->type == 8 && current->is_file_on == 0)
        exit(handel_builtin(current));
    else if (current->is_file_on == 0 && current->type != -1 && current->is_file_on == 0)
    {     
        cmd_path = get_cmd_path(envp_path, current->cmd_name);
        if(!cmd_path)
            return (perror(current->cmd_name), exit(127), 0);
        if (execve(cmd_path, current->av_cmd, current->envp) == -1)
            return (perror(current->cmd_name), exit(EXIT_FAILURE), 0);
        return (1);
    }
    return (exit(0), 0);
}