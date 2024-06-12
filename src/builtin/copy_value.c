/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:14:14 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:14:16 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*copy_value(char *str)
{
	size_t	i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = NULL;
	if (str)
	{
		while (str[i] != '\0' && str[i] != '=')
			i++;
		if (str[i])
			i++;
		new = malloc_and_add(sizeof(char *) * (ft_strlen(str) + 1));
		if (!new)
			return (NULL);
		while (str[i] != '\0')
		{
			new[j] = str[i];
			i++;
			j++;
		}
		new[j] = '\0';
	}
	return (new);
}
