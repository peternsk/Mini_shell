/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:28:28 by peternsaka        #+#    #+#             */
/*   Updated: 2024/02/27 22:38:56 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_space(char c)
{
	if(c == ' ' || c == '\t' || c == '\n')
		return(true);
	return(false);
}
void    find_cmd(t_minish *m_s)
{
	m_s->e = m_s->s;
	while (m_s->input[m_s->e] && (is_space(m_s->input[m_s->e]) == false))
	{
		if(is_meta(m_s->input[m_s->e]) == true)
		{
			m_s->e--;
			create_token(m_s); // token past command
			m_s->e++;
			if(is_meta(m_s->input[m_s->e]) == true)
			{
				m_s->s = m_s->e;
				create_token(m_s);
				m_s->e++;
			}
			m_s->s = m_s->e;
		}
		m_s->e++;
	}
	if(m_s->e > m_s->s)
		create_token(m_s);
	m_s->s = m_s->e;
}
/*
	when meta char are in a odd number(bad print of last node) 
	or are at the end(busserror)
	there's a bug happening
*/