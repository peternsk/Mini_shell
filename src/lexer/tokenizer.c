/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:25:29 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/13 18:44:10 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	flag_switch(char c, t_minish *m_s)
{
	if (c == 34)
		m_s->flags->dbl_flag = FLAG_ON;
	else if (c == 39)
		m_s->flags->sgl_flag = FLAG_ON;
	else if (c == 124 || c == 60 || c == 62)
		m_s->flags->met_flag = FLAG_ON;
	else
		m_s->flags->otc_flag = FLAG_ON;
}

void	split_token(t_minish *m_s)
{
	if (m_s->flags->dbl_flag == FLAG_ON)
	{
		
		m_s->flags->found_flag = FLAG_OFF;
		find_next_quote(m_s, 34);
		m_s->flags->dbl_flag = FLAG_OFF;
	}
	else if (m_s->flags->sgl_flag == FLAG_ON)
	{
		m_s->flags->found_flag = FLAG_OFF;
		find_next_quote(m_s, 39);
		m_s->flags->sgl_flag = FLAG_OFF;
	}
	else if (m_s->flags->met_flag == FLAG_ON)
	{
		find_meta(m_s, m_s->input[m_s->s]);
		m_s->flags->met_flag = FLAG_OFF;
	}
	else if (m_s->flags->otc_flag == FLAG_ON)
	{
		find_cmd(m_s);
		m_s->flags->otc_flag = FLAG_OFF;
	}
}

void	tokenizer(t_minish *m_s)
{
	if (m_s->input == NULL)
		return ;
	while (m_s->input[m_s->e])
	{
		while (m_s->input[m_s->s] && (m_s->input[m_s->s] == ' '
				|| m_s->input[m_s->s] == '\t' || m_s->input[m_s->s] == '\n')
			&& (m_s->read_flag == FLAG_ON))
			m_s->s++;
		flag_switch(m_s->input[m_s->s], m_s);
		if (m_s->input[m_s->e])
			split_token(m_s);
	}
}
