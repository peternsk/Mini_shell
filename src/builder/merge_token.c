/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:13:44 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:13:46 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	merge_token(t_token **lst)
{
	t_token	*cur;

	cur = *lst;
	while (cur != NULL)
	{
		if (cur && (cur->end_token == FLAG_ON))
		{
			printf("Not need to merge :" BLU "%s\n" RESET, cur->value);
		}
		else if (cur && (cur->end_token == FLAG_OFF))
		{
			printf("Need to merge     :" RED "%s\n" RESET, cur->value);
		}
		cur = cur->next;
	}
}

void	delete_token(t_token **lst, int tokToDel_id)
{
	t_token	*cur;

	cur = *lst;
	while (cur->token_id != tokToDel_id)
		cur = cur->next;
	if (cur && cur->next != NULL)
	{
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
	}
	else
		cur->prev->next = NULL;
}

void	combine_tok_value(t_token **lst)
{
	t_token	*cur;
	char	*tmp;

	cur = *lst;
	while (cur != NULL)
	{
		if (cur && (cur->end_token == FLAG_ON && cur->to_merge == FLAG_OFF))
			cur = cur->next;
		if (cur && (cur->end_token == FLAG_OFF && cur->to_merge == FLAG_ON)
			&& cur->next->type != pipe_)
		{
			tmp = ft_strdup(cur->value);
			cur->value = ft_strjoin(tmp, cur->next->value);
			free(tmp);
			cur->end_token = cur->next->end_token;
			cur->to_merge = cur->next->to_merge;
			delete_token(lst, cur->next->token_id);
			add_garbage(cur->value);
		}
		else if (cur)
			cur = cur->next;
	}
}
