/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_childs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:20:09 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/22 23:20:10 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    wait_childs(t_cmd *cmds)
{
    t_cmd *curr;
    curr = NULL;
    if (cmds)
    {
        if (cmds->nb_pipes > 0)
        {
            curr = cmds;
            while (curr != NULL)
            {
                waitpid(curr->id, NULL, 0);
                curr = curr->next;
            }
        }
    }
}