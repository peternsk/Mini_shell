#include "minishell.h"

// t_minish		*init_structs(t_minish *m_s)
// {
// 	m_s = init_ms();
// 	m_s->flags = init_flag();
// 	return(m_s);
// }

void	set_and_update_env(t_minish *m_s, char **env, char **tmp)
{
	if (tmp)
	{
		set_env_lst(m_s, tmp);
		int i = 0;
		while(tmp[i] != NULL)
		{
			free(tmp[i]);
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

int		build_and_exec(t_minish *m_s)
{
	print_expend_tab(&m_s->token_lst, &m_s->env_varlst, m_s);
	ft_remove_quotes(&m_s->token_lst);
	setDelimiter(&m_s->token_lst);
	setFile(&m_s->token_lst);
	printRealList(m_s->token_lst);
	ft_createcomd_lst(m_s);
	merge_token(&m_s->token_lst);
	combine_tok_value(&m_s->token_lst);
	printRealList(m_s->token_lst);
	ft_cmdBuilder(m_s, &m_s->token_lst, &m_s->comd_lst);
	print_comd_lst(&m_s->comd_lst);
	// m_s->update_envp = init_cmds(m_s->tmp, m_s);
	// print_garbage_collector();
	return(0);
}
