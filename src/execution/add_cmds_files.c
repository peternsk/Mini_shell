/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmds_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:59:10 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/05 16:20:46 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    add_cmds_files(t_cmd **node, t_cmd *new, t_redlts *files)
{
    t_cmd *curr;
    if (!*node)
    {
        if (files)
            add_files(new, files);
        *node = new;
        return ;
    }
    curr = *node;
    while (curr->next != NULL)
        curr = curr->next;
    if (files)
        add_files(new, files);
    curr->next = new;
}