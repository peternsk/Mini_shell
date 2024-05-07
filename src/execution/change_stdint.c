/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_stdint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:40:35 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/07 04:12:00 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int put_fd(t_files *current)
{
    int fd;
    
    fd = open(current->name, O_RDONLY);
    if (fd > 0)
    {
        current->manage_fd = init_manage_fd(dup(0), 0, 1);
        current->manage_fd->type = in_p_redir;             
        dup2(fd, 0);
        close(fd);
        return (0);
    }
    return (perror(current->name), -1);
}
int more_stdint(t_files *files)
{
    t_files *current;
    int fd;

    current = files;
    if (current->name)
    {
        while (current->next != NULL && current->type == in_p_redir)
        {
            fd = open(current->name, O_RDONLY);
            if (fd < 0)
                return (close (fd), -1);
            close(fd);
            current = current->next;
        }
        if (current->name && files->type == in_p_redir && current->next == NULL)
           return (put_fd(current));
        return (-1);
    }
    return (0);
}   

int change_stdint(t_files *file)
{

    if (file)
    {
        if (file->name)
        {
            if (file->type == in_p_redir && file->next == NULL) 
                return (put_fd(file));
        }
        else if (file->type == in_p_redir)
            return (more_stdint(file));
              
    }
    return (-1);
}