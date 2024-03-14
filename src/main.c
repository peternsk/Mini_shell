/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:20:31 by peternsaka        #+#    #+#             */
/*   Updated: 2024/03/14 13:50:30 by pnsaka           ###   ########.fr       */
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
			begin_setEnvVar();
			set_env_lst(m_s, env);
			begin_lexing();
			tokenizer(m_s);	
			begin_parsing();
			ft_lexer(&m_s->token_lst, exit_status);
			print_expendTab(&m_s->token_lst, &m_s->envVarlst, m_s);
			print_token(m_s->token_lst);
		}
	}
	else
		printf("arg missing !!\n");
}
