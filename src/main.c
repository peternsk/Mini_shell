/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:20:31 by peternsaka        #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/04/22 14:34:02 by peternsaka       ###   ########.fr       */
=======
/*   Updated: 2024/04/17 17:48:17 by pnsaka           ###   ########.fr       */
>>>>>>> a821058548c14eabef78e89499447142356e26fd
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
			print_garbage_collector();
    		print_env_lst(m_s->envVarlst);
			m_s->tab_env = list_to_tab(&m_s->envVarlst);
		}
	}
	else
		printf("arg missing !!\n");
}
