/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:59:10 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/23 13:41:27 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    add_cmds(t_cmd **node, t_cmd *new)
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