/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:37:56 by pnsaka            #+#    #+#             */
/*   Updated: 2024/03/16 12:36:17 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_quotes(char c)
{
	if(c == 34 || c == 39)
		return(true);
	return(false);
}

void     find_next_quote(t_minish *m_s, char quote_type)
{
	while(m_s->input[m_s->e])
	{
		if(m_s->input[m_s->e] == quote_type && m_s->e > m_s->s)
		{
			create_token(m_s);
			m_s->flags->found_flag = FLAG_ON;
			break;
		}
        m_s->e++;
	}
	if(m_s->flags->found_flag == FLAG_OFF)
	{
		printf("**************************************\n");
		printf("* ERROR : missing ending quotation...*\n");
		printf("**************************************\n");
		return;
	}
	m_s->s = m_s->e + 1;
}
