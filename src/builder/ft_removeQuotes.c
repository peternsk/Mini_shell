/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removeQuotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:12:50 by pnsaka            #+#    #+#             */
/*   Updated: 2024/03/15 09:27:47 by pnsaka           ###   ########.fr       */
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