/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:25:18 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/12 22:33:22 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_quotes(char c)
{
	if (c == 34 || c == 39)
		return (true);
	return (false);
}

void	find_next_quote(t_minish *m_s, char quote_type)
{
	while (m_s->input[m_s->e])
	{
		if (m_s->input[m_s->e] == quote_type && m_s->e > m_s->s)
		{
			create_token(m_s);
			m_s->flags->found_flag = FLAG_ON;
			break ;
		}
		m_s->e++;
	}
	if (m_s->flags->found_flag == FLAG_OFF)
		perror("minihell : missing closing quote");
	if(m_s->input[m_s->e] != '\0')
		m_s->s = m_s->e + 1;
	else
		return;
}
