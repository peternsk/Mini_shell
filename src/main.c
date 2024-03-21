/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:20:31 by peternsaka        #+#    #+#             */
/*   Updated: 2024/03/18 13:52:51 by pnsaka           ###   ########.fr       */
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
			print_token(m_s->token_lst);
			ft_removeQuotes(&m_s->token_lst);
			print_token(m_s->token_lst);
			create_cmdLst(m_s);
			print_cmdLst(m_s->cmdLst);
			ft_builder(m_s->cmdLst, &m_s->token_lst);
			print_cmdLst(m_s->cmdLst);
			
		}
	}
	else
		printf("arg missing !!\n");
}
// echo $USER$?$USER
// echo "'"$USER"'"
// echo bonjour comment ca va
// echo | ls | grep everything | $USER | path
// "e"'c'ho 'b'"o"nj"o"'u'r
