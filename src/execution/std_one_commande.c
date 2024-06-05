#include "minishell.h"


t_files    *give_last_file_stdout(t_files *files)
{
    t_files *tmp;
    t_files *last_files;

    last_files = NULL;
    if (files)
    {
        tmp = files;
        while (tmp != NULL)
        {
            if (tmp->type == APOR || tmp->type == OPR)
                last_files = tmp;
            tmp = tmp->next;
        }
    }
    return (last_files);
}

void    is_output_change(t_cmd *current)
{
    t_files *out;
    int     fd;

    out = give_last_file_stdout(current->files);
    if (out)
    {
        if (out->type == APOR)
            fd = open(out->name, O_WRONLY | O_APPEND ,  07777);
        else 
            fd = open(out->name, O_WRONLY | O_CREAT | O_TRUNC,  07777);
        dup2(fd, 1);
        close(fd);
    }      
}

void std_one_commande(t_cmd *current)
{
    t_files *stdint_files;
    int     fd;
    stdint_files = is_there_here_doc(current);
    if (stdint_files)
    {
        if (stdint_files->type == here_doc)
        {
            stdint_files->name_here_doc = ft_strjoin("/tmp/heredoc", ft_itoa(stdint_files->heredoc_id));
            fd = open(stdint_files->name_here_doc, O_RDONLY, 07777);
        }
        else    
            fd = open(stdint_files->name, O_RDONLY, 07777);
        dup2(fd, 0);
        close(fd);
    }
    is_output_change(current);
}