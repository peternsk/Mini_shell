/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:15:29 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/14 00:04:05 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*free_node(t_env *env)
{
	if (env)
	{
		free(env->key);
		free(env->value);
		free(env);
	}
	return (NULL);
}

void	remove_from_env(t_env *node, int remove)
{
	int		index;
	t_env	*current;
	t_env	*n_node;

	index = 0;
	current = node;
	n_node = NULL;
	while (current != NULL && index != remove)
	{
		index++;
		n_node = current;
		current = current->next;
	}
	if (current == NULL)
		return ;
	n_node->next = current->next;
}

void	index_search_env(char **env, int index)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (i == index)
		{
			return ;
		}
		i++;
	}
}

char	*copy_key_pars_unset(char *str)
{
	int		i;
	char	*new;

	i = 0;
	new = NULL;
	if (str)
	{
		while (str[i] != '\0' && str[i] == '=')
			i++;
		new = malloc_and_add(sizeof(char *) * (i + 1));
		if (!new)
			return (NULL);
		i = 0;
		while (str[i] != '\0' && str[i] != '=')
		{
			new[i] = str[i];
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}

void	ft_unset(t_cmd *unset)
{
	t_env	*linked_node;
	int		i;
	int		remove;

	linked_node = unset->glob->env_varlst;
	i = 1;
	remove = 0;
	while (unset->av_cmd[i] != NULL)
	{
		remove = is_same_key(linked_node,
				copy_key_pars_unset(unset->av_cmd[i]));
		if (remove > -1)
		{
			remove_from_env(linked_node, remove);
		}
		i++;
	}
}
