/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:26:53 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/13 23:44:21 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	prs_ast_pipe(t_token **lst)
{
	t_token	*current;

	current = *lst;
	while (current != NULL)
	{
		if ((current->type == pipe_ && (current->prev == NULL
					|| current->next == NULL)) || current->type == DBLP)
		{
			return (false);
		}
		current = current->next;
	}
	return (true);
}

bool	prs_ast_redir(t_token **lst)
{
	t_token	*current;

	current = *lst;
	while (current != NULL)
	{
		if ((current->type >= OPR && current->type <= here_doc)
			&& (current->prev == NULL && current->next == NULL))
		{
			return (false);
		}
		if ((current->type >= OPR && current->type <= here_doc)
			&& (current->next == NULL))
		{
			return (false);
		}
		current = current->next;
	}
	return (true);
}

bool	prs_ast_dlb_meta(t_token **lst)
{
	t_token	*cur;

	cur = *lst;
	while (cur != NULL)
	{
		if ((cur && (cur->type >= OPR && cur->type <= DBLE)) && (cur->next
				&& (cur->next->type == here_doc)))
			cur = cur->next;
		if ((cur && (cur->type >= OPR && cur->type <= DBLE)) && (cur->next
				&& (cur->next->type == APOR || (cur->next->type >= pipe_
						&& cur->next->type <= DBLE))))
			return (false);
		else if ((cur->type >= OPR && cur->type <= DBLE) && (cur->prev == NULL)
			&& (cur->next == NULL))
			return (false);
		cur = cur->next;
	}
	return (true);
}

bool	ft_lexer(t_token **lst)
{
	if (prs_ast_pipe(lst) == false || prs_ast_dlb_meta(lst) == false
		|| prs_ast_redir(lst) == false)
	{
		g_exit_status = 0;
		g_exit_status = g_exit_status + 2;
		write(2, "minisell: syntax error near unexpected token\n",
			ft_strlen("minisell: syntax error near unexpected token\n")
			);
		return (false);
	}
	return (true);
}
