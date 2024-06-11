
#include "minishell.h"

void	ft_here_exit_status(t_heredoc *token, t_minish *m_s)
{
	char	*exit_code;

	(void)m_s;
	exit_code = ft_itoa(g_exit_status);
	token->expstr = ft_strjoin(token->expstr, exit_code);
	m_s->e = m_s->e + 2;
	m_s->s = m_s->e;
	add_garbage(token->expstr);
	free(exit_code);
}

void	replace_here_str(t_heredoc *node)
{
	free(node->str);
	node->str = ft_strdup(node->expstr);
	add_garbage(node->str);
	free(node->expstr);
	node->expstr = NULL;
}

void	here_exp(t_heredoc *node, t_env **lst, t_minish *m_s)
{
	char	*tmp_key;
	char	*tmp_exp;

	reset_ms(node, m_s);
	while (node->str[m_s->e])
	{
		if (node->str[m_s->e] == '$' && node->str[m_s->e + 1] == '?')
			ft_here_exit_status(node, m_s);
		if (node->str[m_s->e] == '$' && (node->str[m_s->e + 1] != '\0'))
		{
			tmp_key = find_here_key(node, m_s);
			if (find_key_in_list(lst, tmp_key) == true)
				find_var_env(lst, &node->expstr, tmp_key);
			m_s->s = m_s->e;
		}
		if (node->str[m_s->e] != '$')
		{
			while (node->str[m_s->e] && node->str[m_s->e] != '$')
				m_s->e = m_s->e + 1;
			tmp_exp = ft_substr(node->str, m_s->s, (m_s->e - m_s->s));

			node->expstr = ft_strjoin(node->expstr, tmp_exp);
			add_garbage(node->expstr);
			free(tmp_exp);
		}
	}
	replace_here_str(node);
}

void	herelist_exp(t_heredoc **lst, t_env **env_varlst, t_minish *m_s)
{
	t_heredoc	*last;
	t_env		*cur_env;

	last = *lst;
	cur_env = *env_varlst;
	if (last == NULL)
		printf("empty list change\n");
	while (last != NULL)
	{
		if (char_search(last->str, '$') == true)
			here_exp(last, &cur_env, m_s);
		last = last->next;
	}
}
