/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:20:31 by peternsaka        #+#    #+#             */
/*   Updated: 2024/03/06 11:42:20 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int exit_status = 0;

int		main(int ac, char **av, char **env)
{
	t_minish *m_s;
	(void)av;

	ft_ascii_font();
	if(ac > 0)
	{
		while(1)
		{
			m_s = init_ms();
			m_s->flags = init_flag();
			m_s->input = readline(INPUT);
			add_history(m_s->input);
			begin_lexing();
			set_env_lst(m_s, env);
			tokenizer(m_s);	
			begin_parsing();
			ft_lexer(&m_s->token_lst, exit_status);
		}
	}
	else
		printf("arg missing !!\n");
}
