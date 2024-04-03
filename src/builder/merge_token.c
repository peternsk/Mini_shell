/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:37:12 by pnsaka            #+#    #+#             */
/*   Updated: 2024/04/03 14:03:28 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    merge_token(t_token **lst)
{
    t_token *cur;

    cur = *lst;
    while(cur != NULL)
    {
        if(cur && (cur->endToken == FLAG_ON)){
            printf("Not need to merge :" BLU  "%s\n" RESET, cur->value);
        }
        else if(cur && (cur->endToken == FLAG_OFF)){
            printf("Need to merge     :" RED "%s\n" RESET, cur->value);            
        }
        cur = cur->next;
    }
}