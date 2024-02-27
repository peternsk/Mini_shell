/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 08:05:00 by pnsaka            #+#    #+#             */
/*   Updated: 2024/02/26 23:03:44 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token     *create_token(t_minish *m_s)
{
    int i;

    i = count_token(m_s->token_lst);
	//printf("list size %d\n", i);
    if(i == 0)
        init_token_lst(m_s->token_lst, m_s);
    else
        add_token_to_end(m_s->token_lst, m_s);
    return(m_s->token_lst);
}

void         flag_switch(char c, t_minish *m_s)
{
    if(c == 34) // double quote
        m_s->flags->dbl_flag = FLAG_ON;
    else if(c == 39) // single quote
        m_s->flags->sgl_flag = FLAG_ON;
    // else if(c == 124 || c == 60 || c == 62) // meta char | <  >
    //     m_s->flags->met_flag = FLAG_ON;
    else
        m_s->flags->otc_flag = FLAG_ON; // other char
}

void		split_token(t_minish *m_s)
{
	if(m_s->flags->dbl_flag == FLAG_ON)
	{
		find_next_quote(m_s, 34);
		m_s->flags->dbl_flag = FLAG_OFF;
	}
	else if(m_s->flags->sgl_flag == FLAG_ON)
	{
		find_next_quote(m_s, 39);
		m_s->flags->sgl_flag = FLAG_OFF;
	}
	// if(m_s->flags->met_flag = FLAG_ON)
	// 	// do this
	else if(m_s->flags->otc_flag == FLAG_ON)
	{
		find_cmd(m_s);
		m_s->flags->otc_flag = FLAG_OFF;
	}
}

void        tokenizer(t_minish *m_s)
{
    int i;

    i = -1;
    while(m_s->input[++i])
    {
        while(m_s->input[i] == ' ' || m_s->input[i] == '\t' || m_s->input[i] == '\n')
            i++;
        m_s->s = i;
		flag_switch(m_s->input[i], m_s);
        if(m_s->input)
		{
			split_token(m_s);
            print_token(m_s->token_lst);
		}
    }
}