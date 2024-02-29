/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:28:28 by peternsaka        #+#    #+#             */
/*   Updated: 2024/02/29 12:55:41 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_space(char c)
{
	if(c == ' ' || c == '\t' || c == '\n')
		return(true);
	return(false);
}

void	create_cmd(t_minish *m_s)
{
	m_s->e = m_s->s;
	create_token(m_s);
	m_s->s = m_s->e + 1;
}
void    find_cmd(t_minish *m_s)
{
	m_s->e = m_s->s;
	while (m_s->input[m_s->e] && (is_space(m_s->input[m_s->e]) == false))
	{
		if(is_meta(m_s->input[m_s->e]) == true)
		{
			m_s->e--;
			create_token(m_s);
			m_s->e++;
			m_s->s = m_s->e;
			if(is_meta(m_s->input[m_s->e]) == true)
				find_meta(m_s);
			m_s->s = m_s->e + 1;
		}
		m_s->e++;
	}
	if(m_s->e > m_s->s)
		create_token(m_s);
	m_s->s = m_s->e;
}
