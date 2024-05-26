

#include "minishell.h"

void    ft_endToken(t_token *token, t_minish *m_s)
{   
	if(m_s->input[m_s->e + 1] == ' ' || m_s->input[m_s->e + 1] == '\0' || m_s->input[m_s->e + 1] == '\n'
	|| m_s->input[m_s->e + 1] == '<' || m_s->input[m_s->e + 1] == '>')
    {
        token->endToken = FLAG_ON;
        token->to_merge = FLAG_OFF;
    }
    else if(m_s->input[m_s->e] && m_s->input[m_s->e + 1] && m_s->input[m_s->e + 1] == ' ' && token->next->type != pipe_)
    {
        token->endToken = FLAG_ON;
        token->to_merge = FLAG_ON;
    }
    else if (token->type >= out_p_redir && token->type <= dbl_pipe_)
    {
        token->endToken = FLAG_ON;
        token->to_merge = FLAG_OFF;
    }
    else
    {
        token->endToken = FLAG_OFF;
        token->to_merge = FLAG_ON;
    }
}
