/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_stdout.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:42:20 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/07 19:05:05 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int put_int_fd(t_files *file)
{
    int fd_name;
    if (file->name  && file->made == 0)
    {
        int old_fd = dup(1);
        file->manage_fd = init_manage_fd(old_fd, 0, 1);
        file->made = 1;
        file->manage_fd->type = out_p_redir;
        fd_name = open(file->name, O_WRONLY | O_CREAT ,  07777);
        if (fd_name < 0)
            return (perror(file->name), file->error = 1,  -1);
        printf("remettre les fd a la bonne plasse  file %d \n", old_fd);
        dup2(fd_name, 1);
        close(fd_name);
        return (0);
    }
    return (-1);
}

int _files(t_files *files)
{
    int     fd;
    t_files *current;
    
    if (files)
    {   
        current = files;
        while (current->next != NULL && current->type == out_p_redir)
        {
            if (current->name)
            {
                fd = open(current->name, O_WRONLY | O_CREAT ,  07777);
                current->made = 0;
                close(fd);
                current = current->next;
            }
        }
        if (current->name && current->type == out_p_redir && current->next == NULL)
        {
            printf("name->file : %s\n", current->name);
            return (put_int_fd(current));
        }
        return (-1);
    }
    return (-1);
}

int change_stdout(t_files *files )
{
    if (files)
    {
        if (files->next == NULL && files->type == out_p_redir)
        {
            if (files->name)
            {
                return (put_int_fd(files));
            }
        }
        else if (files->type == out_p_redir)
        {
            if (_files(files) == -1)
                return (0);
        }
    }
    return (0);
}