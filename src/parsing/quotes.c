/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:37:56 by pnsaka            #+#    #+#             */
/*   Updated: 2024/02/26 09:55:13 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void     find_next_quote(t_minish *m_s, char quote_type)
{
    int i;

	i = m_s->s;
	while(m_s->input[i] != quote_type && m_s->input[i])
        i++;
	m_s->e = i;
	if(m_s->e > m_s->s)
		init_token_lst(m_s->token_lst, m_s);
	if(m_s->flags->dbl_flag == FLAG_ON)
		m_s->flags->dbl_flag = FLAG_OFF;
	else if(m_s->flags->sgl_flag == FLAG_ON)
		m_s->flags->sgl_flag = FLAG_OFF;
}