/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addEnvp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:13:57 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:13:59 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_there_key_or_value(char *var)
{
	char	*look;

	look = ft_strchr(var, '=');
	if (look)
	{
		look++;
		if (ft_strlen(look) > 0)
			return (2);
	}
	return (1);
}

char	*copy_key(char *str)
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

void	put_key_value(t_env *env, bool both, char *vars)
{
	if (both)
	{
		env->key = copy_key(vars);
		env->value = copy_value(vars);
	}
	else
	{
		env->key = copy_key(vars);
		env->value = NULL;
	}
}

t_env	*add_envp(char *vars)
{
	t_env	*new;

	new = NULL;
	if (vars)
	{
		new = malloc_and_add(sizeof(t_env));
		if (new)
		{
			if (is_there_key_or_value(vars) == 1)
				put_key_value(new, false, vars);
			if (is_there_key_or_value(vars) == 2)
				put_key_value(new, true, vars);
			new->next = NULL;
		}
	}
	return (new);
}
