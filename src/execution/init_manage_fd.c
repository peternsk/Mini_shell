#include "minishell.h"

t_manage_fds *init_manage_fd(int copy_fd, int error, int is_open)
{
    t_manage_fds *node;

    node = malloc_and_add(sizeof(t_manage_fds));
    if (!node)
        return (NULL);
    node->copy_fd = copy_fd;
    node->error = error;
    node->is_open = is_open;
    node->next = NULL;
    return (node);
}