/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:25:34 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:25:36 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	meta_type(t_token *token)
{
	if (token->value[0] == 124 && ft_strlen(token->value) == 1)
		token->type = pipe_;
	else if (token->value[0] == 124 && ft_strlen(token->value) == 2)
		token->type = DBLP;
	else if (token->value[0] == 60 && ft_strlen(token->value) == 1)
		token->type = IPR;
	else if (token->value[0] == 60 && ft_strlen(token->value) == 2)
		token->type = here_doc;
	else if (token->value[0] == 62 && ft_strlen(token->value) == 1)
		token->type = OPR;
	else if (token->value[0] == 62 && ft_strlen(token->value) == 2)
		token->type = APOR;
}

void	assign_type(t_token *token, t_minish *m_s)
{
	if (m_s->flags->dbl_flag == FLAG_ON)
		token->type = DQA;
	else if (m_s->flags->sgl_flag == FLAG_ON)
		token->type = SQA;
	else if (m_s->flags->met_flag == FLAG_ON)
		meta_type(token);
	else if (m_s->flags->otc_flag == FLAG_ON)
		token->type = argument;
}

void	assign_token_type(t_token **lst, t_minish *m_s)
{
	t_token	*node;

	node = *lst;
	while (node->next != NULL)
	{
		assign_type(node, m_s);
		node = node->next;
	}
}
