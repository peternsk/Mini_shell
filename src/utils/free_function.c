/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:27:33 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:27:35 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_list(t_token **list)
{
	t_token	*tmp;

	if (list)
	{
		while (*list != NULL)
		{
			tmp = (*list)->next;
			free(*list);
			(*list) = tmp;
		}
		*list = NULL;
	}
}

void	free_tabl(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
