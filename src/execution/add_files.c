/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:02:19 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/22 13:00:54 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_files *add_curr_file(t_redlts *new_files)
{
    t_files *files;

    files = malloc(sizeof(t_files));
    if (!files)
        return (NULL);
    files->name = new_files->filename;
    files->index = 0;
    files->made = 0;
    files->error = 0;
    files->index_out = 0;
    files->put_last = 0;
    files->type = type_cmds(new_files->redtype);
    files->next = NULL;
    files->manage_fd = -1;
    return (files);
}

void    add_files(t_cmd *cmd_file, t_redlts *new_files)
{
    t_redlts *curr_new_files;
    t_files *curr_add_files;

    curr_add_files = NULL;
    if (new_files)
    {
        curr_new_files = new_files;
        while (curr_new_files != NULL)
        {
            if (cmd_file->files == NULL)   
                cmd_file->files = add_curr_file(curr_new_files);
            else 
            {
                curr_add_files = cmd_file->files;
                while (curr_add_files->next != NULL)
                    curr_add_files = curr_add_files->next;
                curr_add_files->next = add_curr_file(curr_new_files);
            }
            curr_new_files = curr_new_files->next;
        }
    }
}