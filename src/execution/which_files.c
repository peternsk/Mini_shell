#include "minishell.h"

void    check_last_files(t_files *files)
{
    t_files *node;
    t_files *tmp;

    tmp = NULL;
    node = files;
    while (node != NULL)
    {
        if (node->type == apnd_op_redir || node->type == out_p_redir)
            tmp = node;
        node = node->next;    
    }
    if (tmp)
        tmp->put_last = 1;
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

void    which_files(t_cmd *current)
{
    if (current->files)
    {
        check_last_files(current->files);
        t_files *files = current->files;
        while (files != NULL)
        {            
            ft_append(files);
            change_stdint(files);
            if (is_files_valide(current) == 0)
                change_stdout(files);
            // run_here_redlst(current->glob, &files);
            // herelist_exp(&current->glob->herelst, &current->glob->envVarlst, current->glob);
            files = files->next;
        }
    }
}
