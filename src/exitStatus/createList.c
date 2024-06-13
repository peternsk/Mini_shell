/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createList.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:20:40 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:54:09 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exit_code	*init_exit_lst(t_exit_code *node, pid_t extCode)
{
	node = malloc_and_add(sizeof(t_exit_code));
	if (!node)
		return (0);
	node->prev = NULL;
	node->pid = extCode;
	node->next = NULL;
	return (node);
}

void	add_exit_to_end(t_exit_code **lst, t_exit_code *var)
{
	t_exit_code	*last;

	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = var;
		var->next = NULL;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = var;
	var->prev = last;
}

t_exit_code	*create_exit_code_lst(t_minish *m_s, pid_t extCode)
{
	t_exit_code	*here_node;

	here_node = NULL;
	add_exit_to_end(&m_s->extlst, init_exit_lst(here_node, extCode));
	return (m_s->extlst);
}
