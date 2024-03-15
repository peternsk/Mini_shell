/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findVarEnv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:22:54 by pnsaka            #+#    #+#             */
/*   Updated: 2024/03/14 22:00:22 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


bool    char_search(char *tok_value, char c)
{
    int i;

    i = 0;
    while(tok_value[i] != '\0')
    {
        if(tok_value[i] == c)
        {
            return(true);
        }
        i++;
    }
    return(false);
}

char    *find_tmp_key(t_token *tk, t_minish *m_s)
{
    char    *tmpKey;

    tmpKey = NULL;
    printf("in find key s : %d  e : %d\n", m_s->s , m_s->e);
    while(tk->value[m_s->e] && (tk->value[m_s->e] != '$' || is_space(tk->value[m_s->e]) == false))
        m_s->e++;
    if(m_s->e > m_s->s)
    {
        printf("=== in find key ===\n");
        tmpKey = (char *)malloc((sizeof(char) * (m_s->e - m_s->s)) + 1);
        if(!tmpKey)
            return(0);
        printf("in find key s : e : %d\n", m_s->e);
        ft_strncpy(tmpKey, (tk->value + m_s->s), (m_s->e - m_s->s));
    }
    return(tmpKey);
}

bool 	find_key_in_list(t_env **lst, char *tmpKey)
{
    t_env *curVar;

    curVar = *lst;
    while(curVar != NULL)
    {
        if(ft_strcmp(tmpKey, curVar->key) == true)
        {
			return(true);
        }
        curVar = curVar->next;
    }
    return(false);
}


char    *findVarEnv(t_env **lst, char **tmpvalue, char *tmpKey)
{
    t_env *curVar;
    char *tmpStr;

    curVar = *lst;
    while(curVar != NULL)
    {
        if(ft_strcmp(tmpKey, curVar->key) == true)
        {
            tmpStr = ft_strdup(curVar->value);
            *tmpvalue = ft_strjoin(*tmpvalue, tmpStr);
            free(tmpStr);
        }
        curVar = curVar->next;
    }
    return(0);
}

void    replaceToken(t_token *token, char *tmpTokValue)
{
        free(token->value);
        token->value = ft_strdup(tmpTokValue);
}

void	print_expendTab(t_token **lst, t_env **envVarlst, t_minish *m_s)
{
	t_token *last;
	t_env *curEnv;
	
	last = *lst;
	curEnv = *envVarlst;
	if(last == NULL)
		printf("empty list\n");
	while(last != NULL)
	{
        if((last->type == argument || last->type == dbl_quote_arg) && (char_search(last->value, '$') == true))
        {
            printf("here\n");
            ft_expend(last, envVarlst, m_s);
        }
        printf("result charsearch %d\n", char_search(last->value, '$'));
		last = last->next;
	}
}

/* 
    creer une fonction qui avance dans le token et qui va chercher
    toute les valeurs avant le $ pour le stocked dans une string.
*/

char    *valBefDol(t_token *token)
{
    int i;

    i = 0;
    char *tmpValue;
    while(token->value && token->value[i] != '$')
        i++;
    tmpValue = (char *)malloc((sizeof(char) * i) + 1);
    if(!tmpValue)
        return(0);
    i = 0;
    while(token->value && token->value[i] != '$')
    {
        tmpValue[i] = token->value[i];
        i++;
    }
    tmpValue[i] = '\0';
    return(tmpValue);
}