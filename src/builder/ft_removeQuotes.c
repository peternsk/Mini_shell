/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removeQuotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:12:50 by pnsaka            #+#    #+#             */
/*   Updated: 2024/03/16 23:57:52 by peternsaka       ###   ########.fr       */
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
            last->value = ft_strtrim(last->value, "\'");
        if(last->type == dbl_quote_arg)
            last->value = ft_strtrim(last->value, "\"");
        last = last->next;
    }
}