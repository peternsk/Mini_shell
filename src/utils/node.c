/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:02:55 by peternsaka        #+#    #+#             */
/*   Updated: 2024/02/27 10:01:18 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token 	*set_token(t_token *token, t_minish *m_s)
{
	token = malloc(sizeof(t_token));
	if(!token)
		return(0);
	token->prev = NULL;
	token->value = (char *)malloc((sizeof(char) * (m_s->e - m_s->s)) + 1);
	if(!token->value)
		return(0);
	token->token_id = m_s->index;
	ft_strncpy(token->value, &m_s->input[m_s->s], (m_s->e - m_s->s));
	m_s->index = m_s->index + 1;
	token->next = NULL;
	return(token);
}

void	add_token_to_end(t_token **lst, t_token *token)
{
	t_token	*last;
	
	if(!lst)
		return;
	if(count_token(*lst) == 0)
	{
		*lst = token;
		token->next = NULL;
		return;	
	}
	last = *lst;
	while(last != NULL)
		last = last->next;
	last->next = token;
		
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
		printf("========== token ==============\n");
		printf("= token id : %d         \n", token->token_id);
		printf("= token value : %s      \n", token->value);
		printf("===============================\n");
		token = token->next;
	}
}

t_token     *create_token(t_minish *m_s)
{
	t_token *token;

	token = NULL;
    add_token_to_end(&m_s->token_lst, set_token(token, m_s));
	m_s->s = m_s->e;
    return(m_s->token_lst);
}