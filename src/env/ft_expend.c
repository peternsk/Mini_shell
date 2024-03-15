/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:48:25 by pnsaka            #+#    #+#             */
/*   Updated: 2024/03/14 23:56:22 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_expend(t_token *token, t_env **lst, t_minish *m_s)
{
    char *tmpKey;
    char *tmpExp;
    
    m_s->s = 0;
    m_s->e = 0;
    while(token->value[m_s->e] && token->value[m_s->e] != '$')
        m_s->e = m_s->e + 1;
    token->expValue = ft_substr(token->value, m_s->s, (m_s->e - m_s->s));
    while(token->value[m_s->e])
    {
        if(token->value[m_s->e] == '$')
        {
            m_s->e = m_s->e + 1;
            m_s->s = m_s->e;
            tmpKey = find_tmp_key(token, m_s);
            if(find_key_in_list(lst, tmpKey) == true)
                findVarEnv(lst, &token->expValue, tmpKey);
        }
        if(token->value[m_s->e] != '$')
        {
            while(token->value[m_s->e] && token->value[m_s->e] != '$')
                m_s->e = m_s->e + 1;
            tmpExp = ft_substr(token->value, m_s->s, (m_s->e - m_s->s));
            token->expValue = ft_strjoin(token->expValue, tmpExp);
            free(tmpExp);
        }
    }
    replaceToken(token);
}
// echo "abcdef hij k $USER"