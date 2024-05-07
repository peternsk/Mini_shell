/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_stdint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:40:35 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/07 18:18:55 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


#include "minishell.h"

int put_fd(t_files *current)
{
    int fd;
    
    fd = open(current->name, O_RDONLY);
    if (fd > 0 && current->made == 0)
    {
        current->manage_fd = init_manage_fd(dup(0), 0, 1);
        current->manage_fd->type = in_p_redir;             
        dup2(fd, 0);
        close(fd);
        return (current->made = -1, 0);
    }
    return (close(fd), perror(current->name), current->error = -1, current->made = -1,  -1);
}
int change_stdint(t_files *files)
{
    t_files *current;
    int fd;

    current = files;
    if (current->name)
    {
        while (current->next != NULL && current->type == in_p_redir && current->made == 0)
        {
            fd = open(current->name, O_RDONLY);
            if (fd < 0)
                return (close (fd), perror(current->name), current->error = -1, current->made = -1 -1);
            close(fd);
            current->made = -1;
            current = current->next;
        }
        if (current->name && files->type == in_p_redir && current->next == NULL && current->made == 0) 
           return (put_fd(current));
        return (-1);
    }
    return (0);
}   

// int change_stdint(t_files *file)
// {
//     return (more_stdint(file));
// }