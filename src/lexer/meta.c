/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:35:35 by peternsaka        #+#    #+#             */
/*   Updated: 2024/03/04 14:24:00 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_meta(char c)
{
	if(c == 60 || c == 62 || c == 124)
		return(true);
	return(false);
}
void find_meta(t_minish *m_s, char meta)
{
    m_s->e = m_s->s;
    m_s->in_redr_num = 0;

    if (meta == 60 || meta == 62 || meta == 124)
	{
        m_s->flags->met_flag = FLAG_ON;
        while ((m_s->input[m_s->e] && m_s->input[m_s->e] == meta && m_s->input[m_s->e + 1] == meta) && m_s->in_redr_num < 1)
		{
            m_s->in_redr_num++;
            m_s->e++;
        }
    }
    create_token(m_s);
    m_s->flags->met_flag = FLAG_OFF;
    m_s->in_redr_num = 0;
    m_s->s = m_s->e + 1;
}
