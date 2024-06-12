/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_garb_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:20:57 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/12 00:51:06 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_list_garb(t_garbage **list)
{
	t_garbage	*tmp;

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

void	remove_from_garb(t_garbage **lst, void *add)
{
	t_garbage	*tmp;
	t_garbage	*last;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->next->adresse == add)
		{
			last = tmp->next;
			if (tmp->next->next != NULL)
				tmp->next = tmp->next->next;
			free(last);
		}
		tmp = tmp->next;
	}
}
