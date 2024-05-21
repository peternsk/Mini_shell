/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:59:45 by pnsaka            #+#    #+#             */
/*   Updated: 2024/05/19 13:45:29 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env 	*intEnvVar(t_env *node, char *env_row)
{
    char **envTab;
    
	node = malloc_and_add(sizeof(t_env));
	if(!node)
		return(0);
	node->prev = NULL;
	node->next = NULL;
	if(ft_search_char(env_row, '=') == true)
	{
    	envTab = ft_split(env_row, '=');
		add_garbage(envTab);
    	node->key = ft_strdup(envTab[0]);
		add_garbage(node->key);
    	node->value = ft_strdup(envTab[1]);
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
	return(node);
}

void	add_var_to_end(t_env **lst, t_env *var)
{
	t_env	*last;
	
	if(!lst)
		return;
	if(*lst == NULL)
	{
		*lst = var;
		var->next = NULL;
		return;	
	}
	last = *lst;
	while(last->next != NULL)
		last = last->next;
	last->next = var;
	var->prev =last;
}

t_env     *create_var(t_minish *m_s, char *env_row)
{
	t_env *var;

	var = NULL;
    add_var_to_end(&m_s->envVarlst, intEnvVar(var, env_row));
    return(m_s->envVarlst);
}

void	print_env_lst(t_env *lst)
{
	t_env *last;
	
	last = lst;
	if(last == NULL )
		printf("empty list\n");
	while(last != NULL)
	{
		printf("========== token ==============\n");
		printf("= token prev  : %p           \n", last->prev);
		printf("= token key   : %s          \n", last->key);
		printf("= token value : %s          \n", last->value);
		printf("= token next  : %p           \n", last->next);
		printf("===============================\n");
		printf("                 =\n");
		printf("                 =\n");
		last = last->next;
	}
}

void       set_env_lst(t_minish *m_s, char **env)
{
    int i;

    i = 0;
	if (env)
	{
		while(env[i] != NULL)
		{
			create_var(m_s, env[i]);
			i++;
		}
	}
    // print_env_lst(m_s->envVarlst);
}
