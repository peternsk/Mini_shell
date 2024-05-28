#include "minishell.h"
//stdin
//stdout
//append
void    expand_pipe(t_cmd *current, int **array_pipe)
{
    int fd;

    fd = -1;
    if (is_there_here_doc(current) > 0)
    {
        fd = open(current->files->name_here_doc, O_RDONLY,  07777);
        dup2(fd, 0);
    }
    else
        dup2(array_pipe[current->index - 1][0], 0);

}
void    pipe_connect_and_files(t_cmd *current, int **array_pipe)
{
    int i;
    int fd;

    i = 0;
    if (current->index == 0 && is_there_here_doc(current) > 0)
    {
        fd = open(current->files->name_here_doc, O_RDONLY,  07777);
        dup2(fd,  0); 
    }
    if (current->index != 0)
        expand_pipe(current, array_pipe);
    if (current->next)
    {
        // expand_pipe_stdout(current, array_pipe);
        dup2(array_pipe[current->index][1], 1);
    }
    while ( i < (current)->nb_cmds - 1)
    {
        close(array_pipe[i][0]);
        close(array_pipe[i][1]);
        close(fd);
        i++;
    }
}