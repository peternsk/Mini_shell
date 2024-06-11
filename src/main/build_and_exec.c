
#include "minishell.h"

// t_minish		*init_structs(t_minish *m_s)
// {
// 	m_s = init_ms();
// 	m_s->flags = init_flag();
// 	return(m_s);
// }

void	set_and_update_env(t_minish *m_s, char **env, char **tmp)
{
	int	i;

	if (tmp)
	{
		set_env_lst(m_s, tmp);
		i = 0;
		while (tmp[i] != NULL)
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

int	build_and_exec(t_minish *m_s)
{
	print_expend_tab(&m_s->token_lst, &m_s->env_varlst, m_s);
	ft_remove_quotes(&m_s->token_lst);
	set_delimiter(&m_s->token_lst);
	set_file_red(&m_s->token_lst);
	print_real_list(m_s->token_lst);
	ft_createcomd_lst(m_s);
	merge_token(&m_s->token_lst);
	combine_tok_value(&m_s->token_lst);
	print_real_list(m_s->token_lst);
	ft_cmd_builder(m_s, &m_s->token_lst, &m_s->comd_lst);
	print_comd_lst(&m_s->comd_lst);
	// printf("IN BUILT AND EXEC\n");
	// m_s->update_envp = init_cmds(m_s->tmp, m_s);
	// print_garbage_collector();
	return (0);
}
