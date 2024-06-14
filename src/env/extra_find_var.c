/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_find_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:16:23 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/13 09:01:18 by pnsaka           ###   ########.fr       */
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

char	*fve( t_minish *m_s, t_env **lst, char **tp_vl, char *tmp_key)
{
	t_env	*cur_var;
	char	*tmp_str;

	cur_var = *lst;
	while (cur_var != NULL)
	{
		if (ft_strcmp(tmp_key, cur_var->key) == true)
		{
			tmp_str = ft_strdup(cur_var->value);
			add_garbage(tmp_str);
			*tp_vl = ft_combine(*tp_vl, tmp_str);
			remove_from_garb(&m_s->garbage, &tmp_str);
			tmp_str = NULL;
		}
		cur_var = cur_var->next;
	}
	return (0);
}
