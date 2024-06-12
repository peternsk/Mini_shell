/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_here_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:24:44 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:53:03 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_heredoc	*int_here_lst(t_heredoc *node, t_minish *m_s, char *input)
{
	node = malloc_and_add(sizeof(t_heredoc));
	if (!node)
		return (0);
	node->prev = NULL;
	node->str = ft_strdup(input);
	add_garbage(node->str);
	node->made = false;
	node->expstr = NULL;
	node->index = m_s->index;
	m_s->index = m_s->index + 1;
	node->next = NULL;
	return (node);
}

void	add_here_to_end(t_heredoc **lst, t_heredoc *var)
{
	t_heredoc	*last;

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

t_heredoc	*create_here_lst(t_minish *m_s, char *input)
{
	t_heredoc	*here_node;

	here_node = NULL;
	add_here_to_end(&m_s->herelst, int_here_lst(here_node, m_s, input));
	return (m_s->herelst);
}
