
#include "minishell.h"

void	ft_end_token(t_token *token, t_minish *m_s)
{
	if (m_s->input[m_s->e + 1] == ' ' || m_s->input[m_s->e + 1] == '\0'
		|| m_s->input[m_s->e + 1] == '\n' || m_s->input[m_s->e + 1] == '<'
		|| m_s->input[m_s->e + 1] == '>')
	{
		token->end_token = FLAG_ON;
		token->to_merge = FLAG_OFF;
	}
	else if (m_s->input[m_s->e] && m_s->input[m_s->e + 1] && m_s->input[m_s->e
			+ 1] == ' ' && token->next->type != pipe_)
	{
		token->end_token = FLAG_ON;
		token->to_merge = FLAG_ON;
	}
	else if (token->type >= OPR && token->type <= DBLP)
	{
		token->end_token = FLAG_ON;
		token->to_merge = FLAG_OFF;
	}
	else
	{
		token->end_token = FLAG_OFF;
		token->to_merge = FLAG_ON;
	}
}
