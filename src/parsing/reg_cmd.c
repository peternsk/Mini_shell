/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:28:28 by peternsaka        #+#    #+#             */
/*   Updated: 2024/02/27 14:05:28 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void     find_cmd(t_minish *m_s)
{
	m_s->e = m_s->s + 1;
	while (m_s->input[m_s->e] && (m_s->input[m_s->e] != ' ' && m_s->input[m_s->e] != '\t' && m_s->input[m_s->e] != '\n'))
		m_s->e++;
	if(m_s->e > m_s->s)
		create_token(m_s);
	m_s->s = m_s->e;
}