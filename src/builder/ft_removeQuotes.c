/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removeQuotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:12:50 by pnsaka            #+#    #+#             */
/*   Updated: 2024/04/15 20:35:42 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_removeQuotes(t_token **tkLst)
{
    t_token *last;
    
    last = *tkLst;
    while(last != NULL)
    {
        if(last->type == sgl_quote_arg)
        {
            last->value = ft_strtrim(last->value, "\'");
            add_garbage(last->value);
        }
        if(last->type == dbl_quote_arg)
        {
            last->value = ft_strtrim(last->value, "\"");
            add_garbage(last->value);   
        }
        last = last->next;
    }
}