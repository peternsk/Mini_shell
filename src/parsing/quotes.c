/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:37:56 by pnsaka            #+#    #+#             */
/*   Updated: 2024/02/26 18:26:17 by peternsaka       ###   ########.fr       */
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
		create_token(m_s);
}