/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cout_cmds_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:00:09 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/19 20:00:17 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    cout_cmds_pipes(t_cmd **cmds)
{
    t_cmd   *curr;
    int     i;

    i = 0;
    curr = *cmds;
    while (curr != NULL)
    {
        curr->index = i;
        i++;
        curr = curr->next;
    }
    curr = *cmds;
    while (curr != NULL)
    {
        curr->nb_cmds = i;
        curr->nb_pipes = i  - 1;
        curr = curr->next;
    }
    
}