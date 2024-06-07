#include "minishell.h"


int print_error(t_files *current)
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

int ft_append_fd(t_files *current)
{
    int fd;
    
    if (current->error == 0 && current->made == 0)
    {
        fd = open(current->name, O_WRONLY | O_APPEND | O_CREAT ,  07777);
        if (fd < 0)
            return (close(fd), perror(current->name), current->error = -1, current->made = -1);
        close(fd);
        current->made = -1;
        close(fd);
    }
    return (0);
}
int ft_append(t_files *files)
{
    t_files *current;

    current = files;
    if (current->name)
    {
        while (current != NULL)
        {   
            if (current->type == apnd_op_redir)
                ft_append_fd(current);
            current = current->next;
        }
        return (-1);
    }
    return (0);
}