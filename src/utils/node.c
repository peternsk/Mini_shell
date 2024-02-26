/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:02:55 by peternsaka        #+#    #+#             */
/*   Updated: 2024/02/26 09:19:07 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
	
	============ token struct =============
	typedef	struct s_token
	{
		struct s_token *prev;
		struct s_token *next;
		int	token_id;
		int type;
		char *value;
	} t_token;

	============ token list ==============
	typedef struct	s_minish
	{
		t_token *token_lst;
		t_flags *flags;
		char	*input;
		int 	s;
		int 	e;
	} t_minish;
*/

/*
	on this file i need to create a set of functoin that will :
		-> init a doubly linked list 
		-> create a node(token)
		-> add the node(token) to a doubly linked list
*/

/*
	void	add_node_to_end(t_node *head, int data)
	{
		t_node	*tmp;
		t_node	*current;

		if (data < 2147483647 && data > -2147483648)
		{
			tmp = malloc(sizeof(t_node));
			if (!tmp)
				return ;
			tmp->prev = NULL;
			tmp->data = data;
			tmp->index = -1;
			tmp->next = NULL;
			current = head;
			while (current->next != NULL)
				current = current->next;
			tmp->prev = current;
			current->next = tmp;
		}
		else
			return ;
	}
*/
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
}


