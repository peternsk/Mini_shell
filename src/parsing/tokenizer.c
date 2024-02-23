/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 08:05:00 by pnsaka            #+#    #+#             */
/*   Updated: 2024/02/23 13:36:11 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token     *create_token(t_minish *m_s)
{
    
}

int         flag_switch(char c, t_minish *m_s)
{
    if(c == 34) // double quote
        m_s->flags->dbl_flag = FLAG_ON;
    else if(c == 39) // single quote
        m_s->flags->sgl_flag = FLAG_ON;
    else if(c >= 9 && c <= 13) // white space
        m_s->flags->wsp_flag = FLAG_ON;
    else if(c == 124 || c == 60 || c == 62) // meta char | <  >
        m_s->flags->met_flag = FLAG_ON;
    else
        m_s->flags->otc_flag = FLAG_ON; // other char
}

void        tokenizer(t_minish *m_s)
{
    int i;

    i = 0;
    while(m_s->input[i])
    {
        while(m_s->input[i] == ' ' || m_s->input[i] == '\t' || m_s->input[i] == '\n')
            i++;
        if(m_s->input)
            m_s->s = i;
        
    }
}