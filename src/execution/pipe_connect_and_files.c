#include "minishell.h"

void    change_stdint_pipe(t_cmd *current, int **array_pipe)
{
    t_files *last;
    int     fd;

    last = is_there_here_doc(current);
    if (last)
    {
        if (last->type == here_doc)
        {
            last->name_here_doc = ft_strjoin("/tmp/heredoc", ft_itoa(last->hereID));
            fd = open(last->name_here_doc, O_RDONLY, 07777);
        }
        else
            fd = open(last->name, O_RDONLY, 07777);
        if (current->index == 0 && last)
        {
            dup2(fd, 0);
        }
        else if (current->index != 0 && last)
            dup2(fd, 0);
        close (fd);
    }
    else if (current->index != 0)
        dup2(array_pipe[current->index - 1][0], 0);
}


t_files    *give_last_file_type(t_files *files)
{
    t_files *tmp;
    t_files *last_files;

    last_files = NULL;
    if (files)
    {
        tmp = files;
        while (tmp != NULL)
        {
            if (tmp->type == apnd_op_redir || tmp->type == out_p_redir)
                last_files = tmp;
            tmp = tmp->next;
        }
    }
    return (last_files);
}

void change_stdout_pipe(t_cmd *current, int **array_pipe)
{
    t_files *last;
    int     fd;

    last = give_last_file_type(current->files);
    if (last && current->next)
    {
        if (last->type == apnd_op_redir)
            fd = open(last->name, O_WRONLY | O_APPEND ,  07777);
        else
            fd = open(last->name, O_WRONLY | O_TRUNC | O_CREAT,  07777);
        dup2(fd, 1);
        close(fd);
    }
    else if (current->next)
        dup2(array_pipe[current->index][1], 1);
    if (current->next == NULL && last)
    {
        if (last->type == apnd_op_redir)
            fd = open(last->name, O_WRONLY | O_APPEND ,  07777);
        else
            fd = open(last->name, O_WRONLY | O_TRUNC,  07777);
        dup2(fd, 1);
        close(fd);
    }

}
void    pipe_connect_and_files(t_cmd *current, int **array_pipe)
{
    int i;
    char *file_name;

    i = 0;
    file_name = NULL;
    change_stdint_pipe(current, array_pipe);
    change_stdout_pipe(current, array_pipe);
    while ( i < (current)->nb_cmds - 1)
    {
        close(array_pipe[i][0]);
        close(array_pipe[i][1]);
        i++;
    }
}