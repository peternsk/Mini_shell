/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:55:55 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/23 22:01:18 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void free_list(t_token **list)
{
    t_token *tmp;
    
    if (list)
    {
        while (*list != NULL)
        {
            tmp = (*list)->next;
            free(*list);
            (*list) = tmp;
        }
        *list = NULL;
    }
}