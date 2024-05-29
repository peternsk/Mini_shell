#include "minishell.h"

void    check_last_files(t_files *files)
{
    t_files *node;
    t_files *tmp;
    t_files *tmp_here;


    tmp = NULL;
    tmp_here = NULL;
    node = files;
    while (node != NULL)
    {
        if (node->type == apnd_op_redir || node->type == out_p_redir)
            tmp = node;
        if (node->type == here_doc)
            tmp_here = node;
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
void    which_files(t_cmd *current)
{

    printf("dans which files\n");
    if (current->files)
    {

        check_last_files(current->files);
        t_files *files = current->files;
        ft_append(files);
        change_stdint(files);
        if (is_files_valide(current) == 0)
            change_stdout(files);
        // if (current->nb_pipes == 0 && current->nb_cmds == 1)
            expan_here_doc(current);
        // else
        // {
        //     printf("more than one command \n");
        //     run_here_redlst(current->glob, &files);
        //     herelist_exp(&current->glob->herelst, &current->glob->envVarlst, current->glob);
        // }
    }
}
