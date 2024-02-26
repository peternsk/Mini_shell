/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:02:55 by peternsaka        #+#    #+#             */
/*   Updated: 2024/02/26 15:07:36 by pnsaka           ###   ########.fr       */
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
	token->token_id = m_s->index;
	m_s->index = m_s->index + 1;
	ft_strncpy(token->value, &m_s->input[m_s->s], (m_s->e - m_s->s));
	printf("= token index : %d =\n", token->token_id);
	printf("= token value init : %s =\n", token->value);
	token->next = NULL;
	return(token);
}

void	add_token_to_end(t_token *token, t_minish *m_s)
{
	t_token	*tmp = NULL;
	t_token	*current;

	init_token_lst(tmp, m_s);
	current = token;
	while (current->next != NULL)
		current = current->next;
	tmp->prev = current;
	current->next = tmp;
	token->next = NULL;
}

int		count_token(t_token *token)
{
	int token_num;

	token_num = 0;
	while(token != NULL)
	{
		printf("=====debbug count token=====\n");
		token_num++;
		token = token->next;
	}
	return(token_num);
}

void	print_token(t_token *token)
{
	while(token != NULL)
	{
		t_token *tmp;

		tmp = token;
		printf("========== token ID========\n");
		printf("= token id : %d           =\n", tmp->token_id);
		printf("= token valur : %s        =\n", tmp->value);
		printf("===========================\n");
		tmp = tmp->next;
	}
}

/*
	struct s _token *prev;
	struct s_token *next;
	int	token_id;
	int type;
	char *value;
*/