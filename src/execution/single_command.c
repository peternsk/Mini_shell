#include "minishell.h"


// check the cmd type 
// if is 

int execute_one_command(t_cmd *current, char **envp, char *envp_path)
{
     char	*cmd_path;

    if (!current)
        return (printf("current is NULL"), -1);
    if (current->nb_cmds > 1 && current->nb_pipes > 0 && current->type == 8)
        exit(handel_builtin(current));
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

int    single_command(t_cmd *cmd, char **envp, char *envp_path)
{
    if (cmd)
    {
        which_files(cmd);
        if (cmd->type == 8)
            handel_builtin(cmd);
        else if (cmd->type != -1)
        {
            // printf("why dont' work !!\n");
            cmd->id = fork();
            printf("and there we goo ..\n");
            manage_signal(0);
            if (cmd->id == 0)
            {
                // is on doit change le stdint ou le out ?
                if (execute_one_command(cmd, envp, envp_path) == -1)
                    return (-1);
            }
            else if (cmd->id < 0)
                printf("------Error fork()\n");
            wait_childs(cmd);
            manage_signal(-1);
            return (1);
        }
        return (1);
    }
    return (-1);   
}

void fake_2()
{
    
}