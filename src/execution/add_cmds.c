/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:59:10 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/19 20:40:28 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    add_cmds(t_cmd **node, t_cmd *new, char **envp, t_redlts *files)
{
    t_cmd *curr;
    (void)files;
    if (!*node)
    {
        new->envp = envp;
        // if (files)
        //     new->files = files->filename;
        *node = new;
        return ;
    }
    curr = *node;
    while (curr->next != NULL)
        curr = curr->next;
    new->envp = envp;
    // if (files)
    //     new->files = files->filename;
    (*node)->next = new;
}