#include "minishell.h"

bool        end_key(char c)
{
    if(c == ' ' || c == '\t' || c == '\n' || c == 34 || c == 39)
		return(true);
	return(false);
}

char        *find_here_key(t_heredoc *node, t_minish *m_s)
{
    char    *tmpKey;

    tmpKey = NULL;
    m_s->e = m_s->e + 1;
    m_s->s = m_s->e;
    while(node->str[m_s->e] && (node->str[m_s->e] != '$' && is_space(node->str[m_s->e]) == false && end_key(node->str[m_s->e]) == false))
        m_s->e++;
    if(m_s->e > m_s->s)
    {
        tmpKey = (char *)malloc_and_add((sizeof(char) * (m_s->e - m_s->s)) + 1);
        if(!tmpKey)
            return(0);
        ft_strncpy(tmpKey, (node->str + m_s->s), (m_s->e - m_s->s));
    }
    return(tmpKey);
}


void     reset_ms(t_heredoc *node, t_minish *m_s)
{
    m_s->s = 0;
    m_s->e = 0;
    while(node->str[m_s->e] && node->str[m_s->e] != '$')
        m_s->e = m_s->e + 1;
    node->expstr = ft_substr(node->str, m_s->s, (m_s->e - m_s->s));
    add_garbage(node->expstr);
}
