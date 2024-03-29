/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:30:12 by peternsaka        #+#    #+#             */
/*   Updated: 2024/03/06 10:06:48 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	meta_type(t_token *token)
{
	if(token->value[0] == 124 && ft_strlen(token->value) == 1) // pipe |
		token->type = pipe_;
	else if(token->value[0] == 124 && ft_strlen(token->value) == 2)  // input red <
		token->type = dbl_pipe_;
	else if(token->value[0] == 60 && ft_strlen(token->value) == 1)  // input red <
		token->type = in_p_redir;
	else if(token->value[0] == 60 && ft_strlen(token->value) == 2)  // here doc <<
		token->type = here_doc;
	else if(token->value[0] == 62 && ft_strlen(token->value) == 1)  // output red >
		token->type = out_p_redir;
	else if(token->value[0] == 62 && ft_strlen(token->value) == 2)  // append >>
		token->type = apnd_op_redir;
}

void	assign_type(t_token *token, t_minish *m_s)
{
	if(m_s->flags->dbl_flag == FLAG_ON)
		token->type = dbl_quote_arg;
	else if(m_s->flags->sgl_flag == FLAG_ON)
		token->type = sgl_quote_arg;
	else if(m_s->flags->met_flag == FLAG_ON)
		meta_type(token);
	else if(m_s->flags->otc_flag == FLAG_ON)
		token->type = argument;
}

void	assign_token_type(t_token **lst, t_minish *m_s)
{
	t_token *node;

	node = *lst;
	while(node->next != NULL)
	{
		assign_type(node, m_s);	
		node = node->next;
	}
}