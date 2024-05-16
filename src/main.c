/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:20:31 by peternsaka        #+#    #+#             */
/*   Updated: 2024/05/15 15:07:35 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int exit_status = 0;


int		main(int ac, char **av, char **env)
{
	t_minish *m_s;
	(void)av;
	// int glob_id;

	ft_ascii_font();
	// glob_id = -1;
	if(ac > 0)
	{
		manage_signal(-1);
		while(1)
		{
			/************************* signal *******************/
			/***************************************************/
			m_s = init_ms();
			m_s->flags = init_flag();
			m_s->input = readline(INPUT);
			if (!m_s->input)
				return (printf("exit\n"), 0);
			add_history(m_s->input);
			// begin_setEnvVar();
			set_env_lst(m_s, env);
			// begin_lexing();
			tokenizer(m_s);	
			// begin_parsing();
			/*--------------------------- quit sur deux sur "ls > | > sd" ------------------------*/
			printf("-------- ici ----------- minishell \n");
			ft_lexer(&m_s->token_lst);
			/*-----------------------------------------------------------------------------------*/
			print_expendTab(&m_s->token_lst, &m_s->envVarlst, m_s);
			ft_removeQuotes(&m_s->token_lst);
			setDelimiter(&m_s->token_lst);
			setFile(&m_s->token_lst);
			// printRealList(m_s->token_lst);
			ft_createCmdLst(m_s);
			// merge_token(&m_s->token_lst);
			combineTokValue(&m_s->token_lst);
			// printRealList(m_s->token_lst);
			/*---------------------------------here doc----------------------------------*/
			ft_cmdBuilder(m_s, &m_s->token_lst, &m_s->cmdLst);
			/*---------------------------------here doc----------------------------------*/
			print_cmdLst(&m_s->cmdLst);
			init_cmds(env, m_s);
			// print_garbage_collector();
			m_s->tab_env = list_to_tab(&m_s->envVarlst);
			
		}
	}
	else
		printf("arg missing !!\n");
}
