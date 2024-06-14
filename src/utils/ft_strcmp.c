/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:28:12 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:28:14 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_strcmp(char *tmp_key, char *envKey)
{
	int		i;
	char	*new_key;

	i = 0;
	new_key = ft_strtrim(tmp_key, "\"");
	add_garbage(new_key);
	if (ft_strlen(new_key) != ft_strlen(envKey))
		return (false);
	while (new_key[i] != '\0')
	{
		if (new_key[i] == envKey[i])
			i++;
		else
			return (false);
	}
	return (true);
}
