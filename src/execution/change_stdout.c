/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_stdout.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:42:20 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/05 21:31:08 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int _files(t_files *files)
{
    int fd;

    if (files)
    {
        while (files->next != NULL && files->type == out_p_redir)
        {
            if (files->name)
            {
                fd = open(files->name, O_WRONLY | O_CREAT ,  07777);
                files = files->next;
                close (fd);
            }
        }
        if (files->name && files->type == out_p_redir && files->next == NULL)
        {
            fd = open(files->name, O_WRONLY | O_CREAT ,  07777);
            if (fd > 0)
            {
                dup2(fd, 1);
                return (1);
            }
        }
        return (-1);
    }
    return (-1);
}

int change_stdout(t_files *files )
{
    int fd_name;
    int old_fd;
    if (files)
    {
        if (files->next == NULL && files->type == out_p_redir)
        {
            if (files->name)
            {
                old_fd = dup(1);
                fd_name = open(files->name, O_WRONLY | O_CREAT ,  07777);
                if (fd_name < 0)
                    return (perror(files->name), -1);
                printf("remettre les fd la bonne plasse \n");
                dup2(fd_name, 1);
                close(fd_name);
                dup2(old_fd, 1);
                close(old_fd);
                return (1);
            }
        }
        else
        {
            if (_files(files) == -1)
                return (1);
        }
    }
    return (1);
}