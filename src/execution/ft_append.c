/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:36:29 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/05 21:50:52 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// even with no files you create the file whit nothing inside 
// take only one argv;
// is important to close the files .. .. ?

void print_file (t_files *files)
{
    t_files *files_;

    files_ = files;
    printf("=======================\n");
    while (files_ != NULL)
    {
        printf("= file name :%s =\n", files_->name);
        files_  = files_->next;
    }
    printf("=======================\n");
}

int more_files(t_files *files)
{
    int fd;
    t_files *files_;

    files_ = files;
    if (files)
    {
        while (files_->next != NULL && files_->type == apnd_op_redir)
        {
            fd = open(files_->name, O_WRONLY | O_APPEND | O_CREAT ,  07777);
            files_ = files_->next;
            close (fd);
        }
        if (files_->type == apnd_op_redir)
        {    
            fd = open(files_->name, O_WRONLY | O_APPEND | O_CREAT ,  07777);
            if (fd < 0)
                return (perror(files_->name), -1);
            dup2(fd, 1);
            return (1);
        }
    }
    return (-1);
}

int ft_append(t_files *file)
{
    int fd;

    if (file)
    {
        if (file->next == NULL && file->type ==apnd_op_redir)
        {
            printf("the next is NULL\n");
            fd = open(file->name, O_WRONLY | O_APPEND | O_CREAT ,  07777);
            if (fd < 0)
                return (perror(file->name), -1);
            dup2(fd, 1);
            return (1);
        }
        else
        {
            printf("More the one files\n");
            // print_file(file);
            if (more_files(file) == -1)
                return (1);
        }
    }
    return (-1);
}