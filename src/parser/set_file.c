/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:27:16 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:27:18 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_delimiter(t_token **lst)
{
	t_token	*cur;

	cur = *lst;
	while (cur != NULL)
	{
		if (cur->type == here_doc && cur->next != NULL)
		{
			cur = cur->next;
			if (cur->type == argument)
				cur->type = delimter;
		}
		cur = cur->next;
	}
}

void	set_file_red(t_token **lst)
{
	t_token	*cur;

	cur = *lst;
	while (cur != NULL)
	{
		if ((cur->type == here_doc || cur->type == APOR || cur->type == OPR
				|| cur->type == IPR) && cur->next != NULL)
		{
			cur = cur->next;
			if (cur->type == argument)
				cur->type = _file;
		}
		cur = cur->next;
	}
}
