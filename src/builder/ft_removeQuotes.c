/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removeQuotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:13:37 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/13 18:43:34 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_remove_quotes(t_token **tkLst)
{
	t_token	*last;

	last = *tkLst;
	while (last != NULL)
	{
		if (last->type == SQA)
		{
			last->value = ft_strtrim(last->value, "\'");
			add_garbage(last->value);
		}
		if (last->type == DQA)
		{
			last->value = ft_strtrim(last->value, "\"");
			add_garbage(last->value);
		}
		last = last->next;
	}
}
