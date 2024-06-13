/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:17:08 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:17:10 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_cmds(t_cmd **node, t_cmd *new)
{
	t_cmd	*curr;

	if (!*node)
	{
		*node = new;
		return ;
	}
	curr = *node;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
}
