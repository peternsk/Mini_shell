#include "minishell.h"

int execute_command(t_cmd *current, char **envp, char *envp_path)
{
     char	*cmd_path;

    if (!current)
        return (printf("current is NULL"), -1);
    which_files(current);
    if (current->nb_cmds > 1 && current->nb_pipes > 0 && current->type == 8)
        // exit(handel_builtin(current));
        exit(0);
    else
    {     
        cmd_path = get_cmd_path(envp_path, current->cmd_name);
        if(!cmd_path)
            return (exit(EXIT_FAILURE), 0);
        if (execve(cmd_path, current->av_cmd, envp) == -1)
            return (perror("Command error===="), exit(EXIT_FAILURE), 0);
        return (1);
    }
    return (0);
}

void fake_4()
{
    
}