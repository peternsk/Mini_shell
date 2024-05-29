#include "minishell.h"

void    check_last_files(t_files *files, int type)
{
    t_files *node;
    t_files *tmp;

    tmp = NULL;
    node = files;
    if (files)
    {
        while (node != NULL)
        {
            if (node->type == type)
                tmp = node;
            node = node->next;    
        }
        if (tmp)
        {
            printf("%d \n", tmp->put_last = 1);
            tmp->put_last = 1;
        }
            
    }
}

void   print_files_index(t_files *files)
{
    t_files *current;

    current = files;
    while (current != NULL)   
    {
        current = current->next;
    }
}

void expan_here_doc(t_cmd *current)
{
    t_cmd *now_shine;

    now_shine = current;
    while (now_shine != NULL)
    {
        if (is_there_here_doc(now_shine) > 0)
        {
            run_here_redlst(now_shine->glob, &now_shine->files);
            herelist_exp(&now_shine->glob->herelst, &now_shine->glob->envVarlst, now_shine->glob);
            manage_signal(-1);
        }
        now_shine = now_shine->next;
    }
}
// faire en sorte que le here doc soit dans un fork() pour single command
void ticket_files(t_cmd *cmd)
{

    check_last_files(cmd->files, here_doc);
    check_last_files(cmd->files, in_p_redir);
    check_last_files(cmd->files, apnd_op_redir);
    check_last_files(cmd->files, out_p_redir);

}
void    which_files(t_cmd *current)
{
    t_files *files;
    t_cmd   *cmd;

    cmd = current;
    while (cmd != NULL)
    {
        ticket_files(cmd);
        files = cmd->files;
        if (cmd->files)
        {
            ft_append(cmd->files);
            change_stdint(cmd->files);
            if (is_files_valide(cmd) == 0)
                change_stdout(cmd->files);
        }
        cmd = cmd->next;
    }
    expan_here_doc(current);
}
