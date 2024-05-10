/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:36:29 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/08 09:11:07 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// even with no files you create the file whit nothing inside 
// take only one argv;
// is important to close the files .. .. ?
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
    
    if (current->error == 0)
    {
        
        fd = open(current->name, O_WRONLY | O_APPEND | O_CREAT ,  07777);
        if (fd < 0)
            return (close(fd), perror(current->name), current->error = -1, current->made = -1);
        if (current->put_last == 1)
        {
            current->manage_fd = init_manage_fd(dup(1), 0, 1);
            current->manage_fd->type = apnd_op_redir;
            current->made = -1;
            dup2(fd, 1);
            close(fd);
        }
    }
    return (0);
}
int ft_append(t_files *files)
{
    t_files *current;
    int fd;

    current = files;
    if (current->name)
    {
        while (current->next != NULL && current->type == apnd_op_redir && current->made == 0)
        {
            fd = open(current->name, O_WRONLY | O_APPEND | O_CREAT ,  07777);
            if (fd < 0)
                return (close(fd), perror(current->name), current->error = -1, current->made = -1, -1);
            close(fd);
            current->made = -1;
            current = current->next;
        }
        if (current->name && current->type == apnd_op_redir && current->next == NULL && current->made == 0)
            return (ft_append_fd(current));
        return (-1);
    }
    return (0);
}