/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildRedlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:13:26 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:13:30 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_files	*set_red(char *redtype, char *filename, t_minish *m_s)
{
	t_files	*red_node;

	red_node = malloc_and_add(sizeof(t_files));
	if (!red_node)
		return (NULL);
	red_node->name = filename;
	red_node->index = 0;
	red_node->made = 0;
	red_node->here_count = 0;
	red_node->error = 0;
	red_node->index_out = 0;
	red_node->put_last = 0;
	red_node->type = type_cmds(redtype);
	if (red_node->type == here_doc)
	{
		red_node->heredoc_id = m_s->here_id;
		m_s->here_id = m_s->here_id + 1;
	}
	red_node->next = NULL;
	red_node->manage_fd = -1;
	return (red_node);
}

void	rd_end(t_files **lst, t_files *red_node)
{
	t_files	*last;

	if (*lst == NULL)
	{
		*lst = red_node;
		red_node->next = NULL;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = red_node;
	red_node->prev = last;
}

int	count_nbred_node(t_token **lst)
{
	t_token	*token;
	int		nb_redtok;

	token = *lst;
	nb_redtok = 0;
	while (token && token->type != pipe_)
	{
		if (token && (token->type >= OPR && token->type <= IPR))
			nb_redtok++;
		token = token->next;
	}
	return (nb_redtok);
}
