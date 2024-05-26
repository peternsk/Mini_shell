

#include "minishell.h"

static void     phaseOneExp(t_token *token, t_minish *m_s)
{
    m_s->s = 0;
    m_s->e = 0;
    while(token->value[m_s->e] && token->value[m_s->e] != '$')
        m_s->e = m_s->e + 1;
    token->expValue = ft_substr(token->value, m_s->s, (m_s->e - m_s->s));
    add_garbage(token->expValue);
}

static void    ft_exitStatus(t_token *token, t_minish *m_s)
{
    char *exitCode;
    (void)m_s;
    
    exitCode = ft_itoa(exit_status);
    token->expValue = ft_strjoin(token->expValue, exitCode);
    m_s->e = m_s->e + 2;
    m_s->s = m_s->e;
    add_garbage(token->expValue);
    free(exitCode);
}

void    ft_expend(t_token *token, t_env **lst, t_minish *m_s)
{
    char *tmpKey;
    char *tmpExp;
    
    phaseOneExp(token, m_s);
    while(token->value[m_s->e])
    {
        if(token->value[m_s->e] == '$' && token->value[m_s->e + 1] == '?')
            ft_exitStatus(token, m_s);
        if(token->value[m_s->e] == '$' && (token->value[m_s->e + 1] != '\0'))
        {
            tmpKey = find_tmp_key(token, m_s);
            if(find_key_in_list(lst, tmpKey) == true)
                findVarEnv(lst, &token->expValue, tmpKey);
            m_s->s = m_s->e;
        }
        if(token->value[m_s->e] != '$')
        {
            while(token->value[m_s->e] && token->value[m_s->e] != '$')
                m_s->e = m_s->e + 1;
            tmpExp = ft_substr(token->value, m_s->s, (m_s->e - m_s->s));
            token->expValue = ft_strjoin(token->expValue, tmpExp);
            add_garbage(token->expValue);
            free(tmpExp);
        }
    }
    replaceToken(token);
}
