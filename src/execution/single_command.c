#include "minishell.h"


// check the cmd type 
// if is 
void replace_fd(t_files *files)
{
    if (files)
    {
        while (files != NULL)
        {
            if (files->manage_fd)
            {
                if (files->manage_fd->error == 0)
                {
                    if (files->type == out_p_redir)
                    {
                        dup2(files->manage_fd->copy_fd, 1);
                        close(files->manage_fd->copy_fd);
                    }
                    if (files->type == in_p_redir)
                    {
                        dup2(files->manage_fd->copy_fd, 0);
                        close(files->manage_fd->copy_fd);
                    }
                }
            }
            files = files->next;
        }
    }
}
void clean_cmds(t_cmd *cmds)
{
    replace_fd(cmds->files);
}
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
        cmd->is_file_on = is_files_valide(cmd);
        printf("is file good %d\n", is_files_valide(cmd));
        if (cmd->type == 8 && cmd->is_file_on == 0)
            handel_builtin(cmd);
        else if (cmd->type != -1 && cmd->is_file_on == 0)
        {
            (void)envp_path;
            (void)envp;
            printf("why dont' work !!\n");
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
            return (clean_cmds(cmd), 1);
        }
        return (clean_cmds(cmd), 1);
    }
    return (-1);   
}

void fake_2()
{
    
}