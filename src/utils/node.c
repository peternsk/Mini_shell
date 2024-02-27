/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:02:55 by peternsaka        #+#    #+#             */
/*   Updated: 2024/02/26 23:06:27 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token		*init_token_lst(t_token *token, t_minish *m_s)
{
	token = malloc(sizeof(t_token));
	if(!token)
		return(0);
	token->prev = NULL;
	token->value = (char *)malloc((sizeof(char) * (m_s->e - m_s->s)) + 1);
	if(!token->value)
	{
		free(token);
		return(NULL);
	}
	token->token_id = m_s->index;
	ft_strncpy(token->value, &m_s->input[m_s->s], (m_s->e - m_s->s));
	printf(" ===> index %d\n", token->token_id);
	printf(" ===> command %s\n", token->value);
	m_s->index = m_s->index + 1;
	token->next = NULL;
	return(token);
}

void	add_token_to_end(t_token *token, t_minish *m_s)
{
	printf(" === ADD TOKEN ===\n");
	t_token	*tmp = NULL;
	t_token	*current;

	init_token_lst(tmp, m_s);
	current = token;
	while (current->next != NULL)
		current = current->next;
	tmp->prev = current;
	current->next = tmp;
}

int		count_token(t_token *token)
{
	int token_num;

	token_num = 0;
	while(token != NULL)
	{
		token_num++;
		token = token->next;
	}
	return(token_num);
}

void	print_token(t_token *token)
{

	if(token == NULL )
		printf("empty list\n");
	while(token != NULL)
	{
		printf("========== token ID========\n");
		printf("= token id : %d           =\n", token->token_id);
		printf("= token valur : %s        =\n", token->value);
		printf("===========================\n");
		token = token->next;
	}
}
