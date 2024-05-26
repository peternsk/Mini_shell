#include "minishell.h"

void    ft_here_exitStatus(t_heredoc *token, t_minish *m_s)
{
    char *exitCode;
    (void)m_s;
    
    exitCode = ft_itoa(exit_status);
    token->expstr = ft_strjoin(token->expstr, exitCode);
    m_s->e = m_s->e + 2;
    m_s->s = m_s->e;
    add_garbage(token->expstr);
    free(exitCode);
}

void    replace_here_str(t_heredoc *node)
{
        free(node->str);
        node->str = ft_strdup(node->expstr);
        add_garbage(node->str);
        free(node->expstr);
        node->expstr = NULL;
}

void    hereExp(t_heredoc *node, t_env **lst, t_minish *m_s)
{
    char *tmpKey;
    char *tmpExp;
    
    reset_ms(node, m_s);
    while(node->str[m_s->e])
    {
        if(node->str[m_s->e] == '$' && node->str[m_s->e + 1] == '?')
            ft_here_exitStatus(node, m_s);
        if(node->str[m_s->e] == '$' && (node->str[m_s->e + 1] != '\0'))
        {
            tmpKey = find_here_key(node, m_s);
            if(find_key_in_list(lst, tmpKey) == true)
                findVarEnv(lst, &node->expstr, tmpKey);
            m_s->s = m_s->e;
        }
        if(node->str[m_s->e] != '$')
        {
            while(node->str[m_s->e] && node->str[m_s->e] != '$')
                m_s->e = m_s->e + 1;
            tmpExp = ft_substr(node->str, m_s->s, (m_s->e - m_s->s));
            node->expstr = ft_strjoin(node->expstr, tmpExp);
            add_garbage(node->expstr);
            free(tmpExp);
        }
    }
    replace_here_str(node);
}

void	herelist_exp(t_heredoc **lst, t_env **envVarlst, t_minish *m_s)
{
	t_heredoc *last;
	t_env *curEnv;
	
	last = *lst;
	curEnv = *envVarlst;
	if(last == NULL)
		printf("empty list change\n");
	while(last != NULL)
	{
        if(char_search(last->str, '$') == true)
            hereExp(last, &curEnv, m_s);
		last = last->next;
	}
}