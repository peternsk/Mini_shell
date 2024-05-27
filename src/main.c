

#include "../include/minishell.h"

int exit_status = 0;


int		main(int ac, char **av, char **env)
{
	t_minish	*m_s;
	char 		**update_envp;
	char		**tmp;
	(void)av;

	ft_ascii_font();
	tmp = NULL;
	m_s = NULL;
	update_envp = NULL;
	if(ac > 0)
	{
		manage_signal(-1);
		while(1)
		{
			m_s = init_ms();
			m_s->flags = init_flag();
			m_s->input = readline(INPUT);
			if (!m_s->input)
			{
				return (printf("exit\n"), 0);
			}
			add_history(m_s->input);
			// begin_setEnvVar();
			if (update_envp)
			{
				set_env_lst(m_s, update_envp);
				int i = 0;
				while (update_envp[i] != NULL)
				{
					free(update_envp[i]);
					i++;
				}
				update_envp = NULL;
			}
			else
				set_env_lst(m_s, env);
			// begin_lexing();
			tokenizer(m_s);	
			// begin_parsing();
			if(ft_lexer(&m_s->token_lst) == true)
			{
				print_expendTab(&m_s->token_lst, &m_s->envVarlst, m_s);
				ft_removeQuotes(&m_s->token_lst);
				setDelimiter(&m_s->token_lst);
				setFile(&m_s->token_lst);
				printRealList(m_s->token_lst);
				ft_createCmdLst(m_s);
				merge_token(&m_s->token_lst);
				combineTokValue(&m_s->token_lst);
				printRealList(m_s->token_lst);
				ft_cmdBuilder(m_s, &m_s->token_lst, &m_s->cmdLst);
				print_cmdLst(&m_s->cmdLst);
				update_envp = init_cmds(tmp, m_s);
				// print_garbage_collector();
			}
		}
	}
	else
		printf("arg missing !!\n");
}
