/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setFile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:01:00 by pnsaka            #+#    #+#             */
/*   Updated: 2024/04/04 23:38:30 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    setDelimiter(t_token **lst)
{
    t_token *cur;
    
    cur = *lst;
    while(cur != NULL)
    {
        if(cur->type == here_doc && cur->next != NULL)
        {
            cur = cur->next;
            if(cur->type == argument)
                cur->type = delimter;
        }
        cur = cur->next;
    }
}

void    setFile(t_token **lst)
{
    t_token *cur;
    
    cur = *lst;
    while(cur != NULL)
    {
        if((cur->type == here_doc || cur->type == apnd_op_redir || cur->type == out_p_redir || cur->type == in_p_redir) && cur->next != NULL)
        {
            cur = cur->next;
            if(cur->type == argument)
                cur->type = _file;
        }
        cur = cur->next;
    }
}