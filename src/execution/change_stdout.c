/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_stdout.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:42:20 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/22 23:42:21 by mnshimiy         ###   ########.fr       */
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
    int fd;

    if (files)
    {
        if (files->next == NULL)
        {
            if (files->name)
            {
                fd = open(files->name, O_WRONLY | O_CREAT ,  07777);
                if (fd < 0)
                    return (perror("file did't make it"), -1);
                dup2(fd, 1);
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