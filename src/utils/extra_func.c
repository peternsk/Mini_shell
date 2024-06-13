/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:35:14 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/13 10:21:17 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_add_envp(t_env *old_envp, char **arg)
{
	t_env	*node;
	char	**vars;
	int		add;
	int		i;

	i = 0;
	node = old_envp;
	vars = check_duplicate(arg);
	while (vars[i] != NULL)
	{
		if (is_valide(vars[i]) == 0 && ft_strlen(vars[i]) > 0)
		{
			add = is_same_key(node, copy_key_pars(vars[i]));
			if (is_key(vars[i]) == true)
			{
				is_same_key_value(node, vars[i], add);
				where_to_envp(&old_envp, vars[i], add);
			}
			else
				where_to_envp(&old_envp, vars[i], add);
			g_exit_status = 0;
		}
		i++;
	}
}

void	run_here_redlst(t_minish *m_s, t_files **lst)
{
	t_files	*tmp;
	int		here_nbr;

	tmp = *lst;
	here_nbr = count_here_doc(lst);
	while (tmp)
	{
		if ((tmp->type == here_doc) && (tmp->heredoc_id < here_nbr))
			empty_heredoc(tmp);
		if ((tmp->type == here_doc) && tmp->made == 0)
		{
			tmp->made = -1;
			last_here_doc(m_s, tmp);
			send_2_tmp(&m_s->herelst, m_s, tmp, tmp->heredoc_id);
		}
		tmp = tmp->next;
	}
}

void	find_cmd(t_minish *m_s)
{
	m_s->e = m_s->s;
	while (m_s->input[m_s->e] && !is_space(m_s->input[m_s->e]))
	{
		m_s->flags->otc_flag = FLAG_ON;
		if (is_meta(m_s->input[m_s->e]) || is_quotes(m_s->input[m_s->e]))
		{
			set_char_before_meta(m_s);
			if (is_meta(m_s->input[m_s->e]))
				set_meta(m_s);
			if (is_quotes(m_s->input[m_s->e]))
				set_quotes(m_s);
		}
		m_s->e++;
	}
	if (m_s->e > m_s->s)
	{
		m_s->e--;
		create_token(m_s);
	}
	m_s->s = m_s->e + 1;
}

bool	is_char_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (true);
		i++;
	}
	return (false);
}

bool	check_quote(t_token **lst)
{
	t_token	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if ((tmp->type == DQA) && (is_char_in_str(tmp->value, '\"') == true))
			return (false);
		tmp = tmp->next;
	}
	return (true);
}
