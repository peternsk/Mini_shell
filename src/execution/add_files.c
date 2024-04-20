/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:02:19 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/19 20:43:33 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_files *add_curr(t_redlts *new_files)
{
    t_files *files;

    files = malloc(sizeof(t_files));
    if (!files)
        return (NULL);
    files->name = new_files->filename;
    files->type = 
    files->next = NULL;
}

void    add_files(t_files **files, t_redlts *new_files)
{
    t_redlts *curr_new_files;
    t_files *curr_add_files;

    if (new_files)
    {
        curr_new_files = new_files;
        while (curr_new_files != NULL)
        {
            if (!*files)
                *files = add_curr(curr_new_files);
            else 
            {
                curr_add_files = *files;
                while (curr_add_files->next!= NULL)
                    curr_add_files = curr_add_files;
                curr_add_files->next = add_curr(curr_new_files);
            }
            curr_add_files = curr_add_files->next;
        }
    }
}