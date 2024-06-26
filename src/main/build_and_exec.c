/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_and_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:25:39 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/12 22:25:38 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_and_update_env(t_minish *m_s, char **env, char **tmp)
{
	int	i;

	if (tmp)
	{
		set_env_lst(m_s, tmp);
		i = 0;
		while (tmp[i] != NULL)
		{
			i++;
		}
		tmp = NULL;
	}
	else
	{
		set_env_lst(m_s, env);
	}
	tokenizer(m_s);
}

int	build_and_exec(t_minish *m_s)
{
	print_expend_tab(&m_s->token_lst, &m_s->env_varlst, m_s);
	ft_remove_quotes(&m_s->token_lst);
	if (check_quote(&m_s->token_lst) == true)
	{
		set_delimiter(&m_s->token_lst);
		set_file_red(&m_s->token_lst);
		ft_createcomd_lst(m_s);
		combine_tok_value(&m_s->token_lst);
		ft_cmd_builder(m_s, &m_s->token_lst, &m_s->comd_lst);
	}
	return (0);
}
