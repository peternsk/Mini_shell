/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:37:56 by pnsaka            #+#    #+#             */
/*   Updated: 2024/02/27 08:05:14 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void     find_next_quote(t_minish *m_s, char quote_type)
{
	while(m_s->input[m_s->e] && m_s->input[m_s->e] != quote_type)
        m_s->e++;
	if(m_s->e > m_s->s)
		create_token(m_s);
}