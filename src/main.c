/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:20:31 by peternsaka        #+#    #+#             */
/*   Updated: 2024/04/15 21:17:16 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int exit_status = 0;

// static struct s_garbage garb_coll = {0, 0, 0}; 

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
			ft_lexer(&m_s->token_lst);
			print_expendTab(&m_s->token_lst, &m_s->envVarlst, m_s);
			ft_removeQuotes(&m_s->token_lst);
			setDelimiter(&m_s->token_lst);
			setFile(&m_s->token_lst);
			printRealList(m_s->token_lst);
			ft_createCmdLst(m_s);
			merge_token(&m_s->token_lst);
			combineTokValue(&m_s->token_lst);
			printRealList(m_s->token_lst);
			ft_cmdBuilder(&m_s->token_lst, &m_s->cmdLst);
			print_cmdLst(&m_s->cmdLst);
			// print_garbage_collector();
		}
	}
	else
		printf("arg missing !!\n");
}
