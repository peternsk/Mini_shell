/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:28:28 by peternsaka        #+#    #+#             */
/*   Updated: 2024/02/26 14:13:18 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void     find_cmd(t_minish *m_s)
{
    int i;

	i = m_s->s;
	while (m_s->input[i] && (m_s->input[i] != ' ' && m_s->input[i] != '\t' && m_s->input[i] != '\n'))
		i++;
	m_s->e = i;
	if(m_s->e > m_s->s)
		create_token(m_s);
	m_s->flags->otc_flag = FLAG_OFF;
}