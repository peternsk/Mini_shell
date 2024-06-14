/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:26:15 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/13 23:46:32 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int			g_exit_status = 0;

static int	extra_main(char **env)
{
	t_minish	*m_s;
	char		**tmp;

	tmp = NULL;
	m_s = NULL;
	while (1)
	{
		m_s = init_ms();
		m_s->error_pars = 0;
		m_s->flags = init_flag();
		m_s->input = readline(INPUT);
		if (!m_s->input)
			return (all_free(), printf("exit\n"), 0);
		add_history(m_s->input);
		set_and_update_env(m_s, env, tmp);
		if (ft_lexer(&m_s->token_lst) == true)
		{
			if (build_and_exec(m_s) == true)
				tmp = init_cmds(tmp, m_s);
		}
	}
}

int	main(int ac, char **av, char **env)
{
	(void)av;
	(void)ac;
	if (ac > 0)
	{
		ft_ascii_font();
		extra_main(env);
	}
}
