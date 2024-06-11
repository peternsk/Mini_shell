

#include "minishell.h"

t_env	*int_env_var(t_env *node, char *env_row)
{
	char	**env_tab;

	node = malloc_and_add(sizeof(t_env));
	if (!node)
		return (0);
	node->prev = NULL;
	node->next = NULL;
	if (ft_search_char(env_row, '=') == true)
	{
		env_tab = ft_split(env_row, '=');
		add_garbage_arr(env_tab);
		node->key = ft_strdup(env_tab[0]);
		add_garbage(node->key);
		node->value = ft_strdup(env_tab[1]);
		add_garbage(node->value);
		node->eql_sign = true;
	}
	else
	{
		node->key = ft_strdup(env_row);
		add_garbage(node->key);
		node->value = NULL;
		node->eql_sign = false;
	}
	return (node);
}

void	add_var_to_end(t_env **lst, t_env *var)
{
	t_env	*last;

	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = var;
		var->next = NULL;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = var;
	var->prev = last;
}

t_env	*create_var(t_minish *m_s, char *env_row)
{
	t_env	*var;

	var = NULL;
	add_var_to_end(&m_s->env_varlst, int_env_var(var, env_row));
	return (m_s->env_varlst);
}


void	set_env_lst(t_minish *m_s, char **env)
{
	int	i;

	i = 0;
	if (env)
	{
		while (env[i] != NULL)
		{
			create_var(m_s, env[i]);
			i++;
		}
	}
	// print_env_lst(m_s->env_varlst);
}
