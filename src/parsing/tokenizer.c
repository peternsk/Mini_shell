/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 08:05:00 by pnsaka            #+#    #+#             */
/*   Updated: 2024/02/26 09:46:28 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// t_token     *create_token(t_minish *m_s)
// {
    
// }

void         flag_switch(char c, t_minish *m_s)
{
    if(c == 34) // double quote
        m_s->flags->dbl_flag = FLAG_ON;
    else if(c == 39) // single quote
        m_s->flags->sgl_flag = FLAG_ON;
    // else if(c >= 9 && c <= 13) // white space
    //     m_s->flags->wsp_flag = FLAG_ON;
    // else if(c == 124 || c == 60 || c == 62) // meta char | <  >
    //     m_s->flags->met_flag = FLAG_ON;
    else
	{
		printf("===debbug flag_switch start===\n");
        m_s->flags->otc_flag = FLAG_ON; // other char
		printf("===debbug flag_switch end===\n");
	}
}

void		split_token(t_minish *m_s)
{
	if(m_s->flags->dbl_flag == FLAG_ON)
		find_next_quote(m_s, 34);
	else if(m_s->flags->sgl_flag == FLAG_ON)
		find_next_quote(m_s, 39);
	// if(m_s->flags->wsp_flag = FLAG_ON)
	// 	// do this
	// if(m_s->flags->met_flag = FLAG_ON)
	// 	// do this
	else if(m_s->flags->otc_flag == FLAG_ON)
		find_cmd(m_s);
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
		{
            m_s->s = i;
			printf("===debbug start===\n");
			flag_switch(m_s->input[i], m_s);
			printf("===debbug end===\n");
			split_token(m_s);
		}
    }
}