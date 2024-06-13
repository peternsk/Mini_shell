/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_find_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:16:23 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/12 00:23:10 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
