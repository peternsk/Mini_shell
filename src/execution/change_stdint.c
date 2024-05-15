/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_stdint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:40:35 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/09 16:59:21 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    
    fd = open(current->name, O_RDONLY);
    if (current->error == 0)
    {
        if (fd > 0 && current->made == 0)
        {
            current->manage_fd = init_manage_fd(dup(0), 0, 1);
            current->manage_fd->type = in_p_redir;             
            dup2(fd, 0);
            close(fd);
            return (current->made = -1, 0);
        }
        return (put_error(current),  perror(current->name), close(fd), current->error = -1, current->made = -1,  -1);
        // return (put_error(current), close(fd),  current->error = -1, current->made = -1,  -1);
    }
    return (0);
}
int change_stdint(t_files *files)
{
    t_files *current;
    int fd;

    current = files;
    if (current)
    {
        while (current->next != NULL && current->type == in_p_redir && current->made == 0)
        {
            if (current->error == 0)
            {
                fd = open(current->name, O_RDONLY);
                if (fd < 0)
                    return (put_error(files),  perror(current->name), close (fd),current->error = -1, current->made = -1,  -1);
                close(fd);
                current->made = -1;
            }
            current = current->next;
        }
        if (current->name && current->type == in_p_redir && current->next == NULL && current->made == 0) 
           return (put_fd(current));
        return (-1);
    }
    return (0);
}   

// int change_stdint(t_files *file)
// {
//     return (more_stdint(file));
// }