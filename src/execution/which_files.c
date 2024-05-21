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
    // printf("tmp->index_ou %d\n tmp->name %s\n", tmp->index_out, tmp->name);
}
void   print_files_index(t_files *files)
{
    t_files *current;

    current = files;
    while (current != NULL)   
    {
        printf("------\ncurrent-last : %d \ncurrent-type %d\n current->name %s\n---------\n", current->index_out, current->type, current->name);
        current = current->next;
    }
}

void    which_files(t_cmd *current)
{
    print_files_index(current->files);
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
            run_here_redlst(current->glob, &files);
            herelist_exp(&current->glob->herelst, &current->glob->envVarlst, current->glob);
	        print_here_lst(current->glob->herelst);
            files = files->next;
        }
    }
}
