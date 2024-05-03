/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_childs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:20:09 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/03 18:02:46 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    wait_childs(t_cmd *cmds)
{
    t_cmd *curr;
    curr = NULL;
    if (cmds)
    {
        curr = cmds;
        while (curr != NULL)
        {
            waitpid(curr->id, NULL, 0);
            curr = curr->next;
        }
    }
}