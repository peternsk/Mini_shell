#include "minishell.h"

t_minish		*init_structs(t_minish *m_s)
{
	m_s = init_ms();
	m_s->flags = init_flag();
	return(m_s);
}

void	set_and_update_env(t_minish *m_s, char **env)
{
	if (m_s->update_envp)
	{
		set_env_lst(m_s, m_s->update_envp);
		int i = 0;
		while (m_s->update_envp[i] != NULL)
		{
			free(m_s->update_envp[i]);
			i++;
		}
		m_s->update_envp = NULL;
	}
	else
		set_env_lst(m_s, env);
	tokenizer(m_s);
}

int		build_and_exec(t_minish *m_s)
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
	m_s->update_envp = init_cmds(m_s->tmp, m_s);
	print_garbage_collector();
	return(0);
}
