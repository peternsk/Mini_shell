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
            // printf("why dont' work !!\n");
            cmd->id = fork();
            manage_signal(0);
            if (cmd->id == 0)
            {
                // is on doit change le stdint ou le out ?
                if (execute_command(cmd, envp, envp_path) == -1)
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