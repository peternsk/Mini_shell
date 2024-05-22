#include "minishell.h"

// ajouter la function qui dis le bon put error 
int execute_command(t_cmd *current, char **envp, char *envp_path)
{
    char	*cmd_path;

    if (!current)
        return (printf("current is NULL"), -1);
    which_files(current);
    current->is_file_on = is_files_valide(current);
    if (current->nb_cmds > 1 && current->nb_pipes > 0 && current->type == 8 && current->is_file_on == 0)
        exit(handel_builtin(current));
    else if (current->is_file_on == 0 && current->type != -1 && current->is_file_on == 0)
    {     
        cmd_path = get_cmd_path(envp_path, current->cmd_name);
        if(!cmd_path)
            return (perror(current->cmd_name), exit(EXIT_FAILURE), 0);
        if (execve(cmd_path, current->av_cmd, envp) == -1)
            return (perror(current->cmd_name), exit(EXIT_FAILURE), 0);
        return (1);
    }
    return (exit(0), 0);
}