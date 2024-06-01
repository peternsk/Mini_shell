#include "minishell.h"


void cmd_path_error(int error_type, char *message)
{
    write(error_type, "minishell: ", ft_strlen("minishell: "));
    write(error_type, message, ft_strlen(message));
    write(error_type, ": command not found\n", ft_strlen(": command not found\n"));
}

void replace_fd(t_files *files)
{
    if (files)
    {
        while (files != NULL)
        {
            if (files->manage_fd > -1)
            {
                if (files->type == out_p_redir)
                {
                    dup2(files->manage_fd, 1);
                    close(files->manage_fd);
                }
                if (files->type == in_p_redir)
                {
                    dup2(files->manage_fd, 0);
                    close(files->manage_fd);
                }
                if (files->type == apnd_op_redir)
                {
                    dup2(files->manage_fd, 1);
                    close(files->manage_fd);
                }
            }
            files = files->next;
        }
    }
}
void clean_cmds(t_cmd *cmds)
{
    (void) cmds;
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
            return (cmd_path_error(2, current->cmd_name), exit(127),  0);
        if (execve(cmd_path, current->av_cmd, envp) == -1)
            return (perror(cmd_path), exit(EXIT_FAILURE), 0);
        return (1);
    }
    return (0);
}
int     the_last_heredoc(t_cmd *cmd)
{  
    int     i;    

    i = 0;
    while(cmd->files)
    {
        if(cmd->files->type == here_doc)
            i++;
        cmd->files = cmd->files->next;
    }
    return(i);
}

void    change_fd(t_cmd *cmd)
{
    int fd;

    char *file_name;

    file_name = NULL;
    if (is_there_here_doc(cmd) > 0)
    {
        file_name = ft_strjoin("/tmp/heredoc", ft_itoa(the_last_heredoc(cmd)));
        fd =  open(file_name, O_RDONLY,  07777);
        dup2(fd, 0);
        close(fd);
    }
    
}   

int    single_command(t_cmd *cmd, char **envp, char *envp_path)
{
    if (cmd)
    {
        which_files(cmd);
        cmd->is_file_on = is_files_valide(cmd);
        if (cmd->type == 8 && cmd->is_file_on == 0)
            handel_builtin(cmd);
        else if (cmd->type != -1 && cmd->is_file_on == 0)
        {
            cmd->id = fork();
            manage_signal(0);
            if (cmd->id == 0)
            {
                std_one_commande(cmd);
                if (execute_one_command(cmd, envp, envp_path) == -1)
                    return (-1);
            }
            else
                wait_childs(cmd);
        }
        return (1);
    }
    return (-1);   
}
