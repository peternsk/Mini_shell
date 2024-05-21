/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmds_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:59:10 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/16 11:53:41 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    add_cmds_files(t_cmd **node, t_cmd *new)
{
    t_cmd *curr;
    if (!*node)
    {
        *node = new;
        return ;
    }
    curr = *node;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = new;
}