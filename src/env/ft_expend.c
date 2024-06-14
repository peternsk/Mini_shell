/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:16:39 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/13 23:31:53 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	phase_one_exp(t_token *token, t_minish *m_s)
{
	m_s->s = 0;
	m_s->e = 0;
	while (token->value[m_s->e] && token->value[m_s->e] != '$')
		m_s->e = m_s->e + 1;
	token->exp_value = ft_substr(token->value, m_s->s, (m_s->e - m_s->s));
	add_garbage(token->exp_value);
}

static void	ft_exit_status(t_token *token, t_minish *m_s)
{
	char	*exit_code;

	(void)m_s;
	exit_code = ft_itoa(g_exit_status);
	token->exp_value = ft_strjoin(token->exp_value, exit_code);
	m_s->e = m_s->e + 2;
	m_s->s = m_s->e;
	add_garbage(token->exp_value);
	free(exit_code);
}

static void	ft_last_phase(t_token *token, t_minish *m_s)
{
	char	*tmp_exp;

	while (token->value[m_s->e] && token->value[m_s->e] != '$')
		m_s->e = m_s->e + 1;
	tmp_exp = ft_substr(token->value, m_s->s, (m_s->e - m_s->s));
	token->exp_value = ft_strjoin(token->exp_value, tmp_exp);
	add_garbage(token->exp_value);
	free(tmp_exp);
}

static void	ft_bef_last(t_token *token, t_env **lst, t_minish *m_s)
{
	char	*tmp_key;

	tmp_key = NULL;
	tmp_key = find_tmp_key(token, m_s);
	if (find_key_in_list(lst, tmp_key) == true)
		fve(m_s, lst, &token->exp_value, tmp_key);
	m_s->s = m_s->e;
}

void	ft_expend(t_token *token, t_env **lst, t_minish *m_s)
{
	phase_one_exp(token, m_s);
	while (token->value[m_s->e])
	{
		if (token->value[m_s->e] == '$' && token->value[m_s->e + 1] == '?')
			ft_exit_status(token, m_s);
		if (token->value[m_s->e] == '$' && (token->value[m_s->e + 1] == '\"'
				|| token->value[m_s->e + 1] == ' ' || token->value[m_s->e
					+ 1] == '\0'))
		{
			m_s->s = m_s->e;
			m_s->e++;
		}
		if (token->value[m_s->e] == '$' && (token->value[m_s->e + 1] != '\0'))
			ft_bef_last(token, lst, m_s);
		if (token->value[m_s->e] != '$')
			ft_last_phase(token, m_s);
	}
	replace_token(token, m_s);
}
