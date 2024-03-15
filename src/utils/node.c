/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:02:55 by peternsaka        #+#    #+#             */
/*   Updated: 2024/03/14 18:33:44 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token 	*set_token(t_token *token, t_minish *m_s)
{
	token = malloc(sizeof(t_token));
	if(!token)
		return(0);
	token->prev = NULL;
	token->value = (char *)malloc((sizeof(char) * (m_s->e - m_s->s)) + 2);
	if(!token->value)
		return(0);
	token->token_id = m_s->index;
	ft_strncpy(token->value, &m_s->input[m_s->s], ((m_s->e + 1) - m_s->s));
	token->type = -1;
	assign_type(token, m_s);
	token->varTab = NULL;
	token->splitToD = NULL;
	token->expValue = NULL;
	m_s->index = m_s->index + 1;
	token->next = NULL;
	return(token);
}

void	add_token_to_end(t_token **lst, t_token *token)
{
	t_token	*last;
	
	if(!lst)
		return;
	if(*lst == NULL)
	{
		*lst = token;
		token->next = NULL;
		return;	
	}
	last = *lst;
	while(last->next != NULL)
		last = last->next;
	last->next = token;
	token->prev =last;
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

void	print_token(t_token *lst)
{
	t_token *last;
	
	last = lst;
	if(last == NULL )
		printf("empty list\n");
	while(last != NULL)
	{
		printf("========== token ==============\n");
		printf("= token prev  : %p           \n", last->prev);
		printf("= token id    : %d             \n", last->token_id);
		printf("= token value : %s          \n", last->value);
		printf("= token len   : %zu          \n", ft_strlen(last->value));
		printf("= token type  : %d          \n", last->type);
		printf("= token next  : %p           \n", last->next);
		printf("===============================\n");
		printf("                 =\n");
		printf("                 =\n");
		last = last->next;
	}
}

t_token     *create_token(t_minish *m_s)
{
	t_token *token;

	token = NULL;
    add_token_to_end(&m_s->token_lst, set_token(token, m_s));
    return(m_s->token_lst);
}