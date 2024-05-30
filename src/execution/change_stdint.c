
#include "minishell.h"


int put_error(t_files *current)
{
    t_files *node;

    node = current;
    while (node != NULL)
    {
        if (node->type == in_p_redir)
            node->error = -1;
        node = node->next;
    }
    return (0);
}

int put_fd(t_files *current)
{
    int fd;
    
    if (current->error == 0 && current->made == 0)
    {
        fd = open(current->name, O_RDONLY);
        if (fd > -1)
            return (current->made = -1, close(fd), 0);
        return (put_error(current),  perror(current->name), close(fd), current->error = -1, current->made = -1,  -1);
    }
    return (0);
}
int change_stdint(t_files *files)
{
    t_files *current;

    current = files;
    if (current)
    {
        while (current != NULL )
        {
            if (current->type == in_p_redir)
                put_fd(current);
            current = current->next;
        }
        return (0);
    }
    return (0);
}   