/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:28:28 by peternsaka        #+#    #+#             */
/*   Updated: 2024/02/28 13:08:59 by pnsaka           ###   ########.fr       */
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
			printf("2\n");
			sleep(1);
			m_s->e--;
			create_token(m_s);
			m_s->s = m_s->e + 1;
			if(is_meta(m_s->input[m_s->e]) == true)
				find_meta(m_s);
			m_s->s = m_s->e;
		}
		m_s->e++;
		printf("1\n");
		sleep(1);
	}
	if(m_s->e > m_s->s)
	{
		create_token(m_s);
		printf("3\n");
		sleep(1);
	}
	m_s->s = m_s->e;
}
