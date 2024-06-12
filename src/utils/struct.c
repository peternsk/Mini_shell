/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:28:43 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:28:45 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_minish	*init_ms(void)
{
	t_minish	*m_s;

	m_s = malloc_and_add(1 * sizeof(t_minish));
	if (!m_s)
		return (NULL);
	m_s->input = NULL;
	m_s->token_lst = NULL;
	m_s->env_varlst = NULL;
	m_s->update_envp = NULL;
	m_s->comd_lst = NULL;
	m_s->tab_env = NULL;
	m_s->herelst = NULL;
	m_s->update_envp = NULL;
	m_s->unlnk_lst = NULL;
	m_s->here_id = 1;
	m_s->index = 0;
	m_s->pipe_num = 0;
	m_s->in_redr_num = 0;
	m_s->out_redr_num = 0;
	m_s->read_flag = 0;
	m_s->cmd_all_set = 0;
	m_s->cmd_counter = 0;
	m_s->s = 0;
	m_s->e = 0;
	return (m_s);
}

t_flags	*init_flag(void)
{
	t_flags	*flags;

	flags = malloc_and_add(1 * sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->sgl_flag = FLAG_OFF;
	flags->dbl_flag = FLAG_OFF;
	flags->wsp_flag = FLAG_OFF;
	flags->met_flag = FLAG_OFF;
	flags->otc_flag = FLAG_OFF;
	flags->found_flag = FLAG_OFF;
	flags->flag_sw = FLAG_OFF;
	return (flags);
}
