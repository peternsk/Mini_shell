/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cout_cmds_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:00:09 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/10 17:16:42 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    count_files_by_type(t_files *files)
{
    t_files *current;
    int     j;
    int     k;
    int     i;

    i = 0;
    j = 0;
    k = 0;
    current = files;
    while (current != NULL)
    {
        current->index = i;
        if (current->type == apnd_op_redir || current->type == out_p_redir)
        {
            current->index_out = j;
            j++;
        }
        if (current->type == here_doc)
        {
            current->index_out = k;
            k++;
        }
        i++;
        current = current->next;        
    }
}

void    cout_cmds_pipes(t_cmd *cmds)
{
    t_cmd   *curr;
    int     i;

    i = 0;
    curr = cmds;
    while (curr != NULL)
    {
        curr->index = i;
        i++;
        curr = curr->next;
    }
    curr = cmds;
    while (curr != NULL)
    {
        curr->nb_cmds = i;
        curr->nb_pipes = i  - 1;
        if (curr->files)
            count_files_by_type(curr->files);
        curr = curr->next;
    }
   
}