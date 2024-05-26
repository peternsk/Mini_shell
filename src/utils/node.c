

#include "minishell.h"

t_token 	*set_token(t_token *token, t_minish *m_s)
{
	token = malloc_and_add(sizeof(t_token));
	if(!token)
		return(0);
	token->prev = NULL;
	token->value = (char *)malloc_and_add((sizeof(char) * (m_s->e - m_s->s)) + 2);
	if(!token->value)
		return(0);
	token->token_id = m_s->index;
	ft_strncpy(token->value, &m_s->input[m_s->s], ((m_s->e + 1) - m_s->s));
	token->type = -1;
	assign_type(token, m_s);
	token->expValue = NULL;
	m_s->index = m_s->index + 1;
	token->endToken = FLAG_OFF;
	token->to_merge = FLAG_OFF;
	token->setToCmd = FLAG_OFF;
	ft_endToken(token, m_s);
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


t_token     *create_token(t_minish *m_s)
{
	t_token *token;

	token = NULL;
    add_token_to_end(&m_s->token_lst, set_token(token, m_s));
    return(m_s->token_lst);
}