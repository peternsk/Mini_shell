/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:36:58 by pnsaka            #+#    #+#             */
/*   Updated: 2024/03/06 08:39:21 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_minish *init_ms(void)
{
	t_minish	*m_s;

	m_s = malloc(1 * sizeof(t_minish));
	if (!m_s)
		return (NULL);
	m_s->input = NULL;
	m_s->token_lst = NULL;
	m_s->envVarlst = NULL;
	m_s->index = 0;
	m_s->pipe_num = 0;
	m_s->in_redr_num = 0;
	m_s->out_redr_num = 0;
	m_s->read_flag = 0;
    m_s->s = 0;
    m_s->e = 0;
	return(m_s);
}

t_flags *init_flag(void)
{
	t_flags	*flags;

	flags = malloc(1 * sizeof(t_flags));
	if (!flags)
		return (NULL);
    flags->sgl_flag = FLAG_OFF;
    flags->dbl_flag = FLAG_OFF;
    flags->wsp_flag = FLAG_OFF;
    flags->met_flag = FLAG_OFF;
    flags->otc_flag = FLAG_OFF;
	flags->found_flag = FLAG_OFF;
    flags->flag_sw = FLAG_OFF;
	return(flags);
}

