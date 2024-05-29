#include "minishell.h"
//stdin
//stdout
//append
void    expand_pipe(t_cmd *current, int **array_pipe)
{
    int fd;
    char *file_name;

    fd = -1;
    file_name = NULL;
    if (is_there_here_doc(current) > 0)
    {
        file_name = ft_strjoin("/tmp/heredoc", ft_itoa(the_last_heredoc(current)));
        fd = open(file_name, O_RDONLY,  07777);
        dup2(fd, 0);
        close(fd);
    }
    else
        dup2(array_pipe[current->index - 1][0], 0);

}
void    pipe_connect_and_files(t_cmd *current, int **array_pipe)
{
    int i;
    int fd;
    char *file_name;

    i = 0;
    file_name = NULL;
    if (current->index == 0 && is_there_here_doc(current) > 0)
    {
        file_name = ft_strjoin("/tmp/heredoc", ft_itoa(the_last_heredoc(current)));
        fd = open(file_name, O_RDONLY,  07777);
        dup2(fd,  0);
        close(fd);
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