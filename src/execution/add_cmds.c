

#include "minishell.h"

void    add_cmds(t_cmd **node, t_cmd *new)
{
    t_cmd *curr;
    if (!*node)
    {
        *node = new;
        return ;
    }
    curr = *node;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = new;
}