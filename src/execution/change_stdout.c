/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_stdout.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:42:20 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/04 20:22:22 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int _files(t_files *files)
{
    int fd;

    if (files)
    {
        while (files->next != NULL)
        {
            if (files->name)
            {
                fd = open(files->name, O_WRONLY | O_CREAT ,  07777);
                files = files->next;
                close (fd);
            }
        }
        if (files->name)
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

int change_stdout(t_files *files)
{
    int fd_name;
    int old_fd;
    if (files)
    {
        if (files->next == NULL)
        {
            if (files->name)
            {
                old_fd = dup(STDOUT_FILENO);
                fd_name = open(files->name, O_WRONLY | O_CREAT ,  07777);
                if (fd_name < 0)
                    return (perror("file did't make it"), -1);
                printf("remettre les fd la bonne plasse \n");
                dup2(fd_name, STDOUT_FILENO);
                close(fd_name);
                dup2(old_fd, fd_name);
                close(fd_name);
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