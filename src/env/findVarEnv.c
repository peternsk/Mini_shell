

#include "minishell.h"

bool	char_search(char *tok_value, char c)
{
	int	i;

	i = 0;
	while (tok_value[i] != '\0')
	{
		if (tok_value[i] == c)
		{
			return (true);
		}
		i++;
	}
	return (false);
}

char	*find_tmp_key(t_token *tk, t_minish *m_s)
{
	char	*tmp_key;

	tmp_key = NULL;
	m_s->e = m_s->e + 1;
	m_s->s = m_s->e;
	while (tk->value[m_s->e] && (tk->value[m_s->e] != '$'
			&& is_space(tk->value[m_s->e]) == false)
		&& tk->value[m_s->e] != '\"')
		m_s->e++;
	if (m_s->e > m_s->s)
	{
		tmp_key = (char *)malloc_and_add((sizeof(char) * (m_s->e - m_s->s))
				+ 1);
		if (!tmp_key)
			return (0);
		ft_strncpy(tmp_key, (tk->value + m_s->s), (m_s->e - m_s->s));
	}
	return (tmp_key);
}

bool	find_key_in_list(t_env **lst, char *tmp_key)
{
	t_env	*cur_var;

	cur_var = *lst;
	while (cur_var != NULL)
	{
		if (ft_strcmp(tmp_key, cur_var->key) == true)
		{
			return (true);
		}
		cur_var = cur_var->next;
	}
	return (false);
}

char	*find_var_env(t_env **lst, char **tmpvalue, char *tmp_key)
{
	t_env	*cur_var;
	char	*tmp_str;

	cur_var = *lst;
	while (cur_var != NULL)
	{
		if (ft_strcmp(tmp_key, cur_var->key) == true)
		{
			tmp_str = ft_strdup(cur_var->value);
			*tmpvalue = ft_strjoin(*tmpvalue, tmp_str);
			add_garbage(tmpvalue);
			free(tmp_str);
			tmp_str = NULL;
		}
		cur_var = cur_var->next;
	}
	return (0);
}

void	replace_token(t_token *token)
{
	free(token->value);
	token->value = ft_strdup(token->exp_value);
	add_garbage(token->value);
	free(token->exp_value);
}

void	print_expend_tab(t_token **lst, t_env **env_varlst, t_minish *m_s)
{
	t_token	*last;
	t_env	*cur_env;

	last = *lst;
	cur_env = *env_varlst;
	// if (last == NULL)
		// printf("empty list change\n");
	while (last != NULL)
	{
		if ((last->type == argument || last->type == DQA)
			&& (char_search(last->value, '$') == true))
			ft_expend(last, &cur_env, m_s);
		last = last->next;
	}
}
