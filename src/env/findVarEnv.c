/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findVarEnv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:22:54 by pnsaka            #+#    #+#             */
/*   Updated: 2024/03/13 20:55:34 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool    char_search(char *tok_value, char c)
{
    int i;

    i = 0;
    while(tok_value[i])
    {
        if(tok_value[i] == c && tok_value[i + 1])
            return(true);
        i++;
    }
    return(false);
}

char    *find_tmp_key(char *value, int i)
{
    int     start;
    char    *tmpKey;

    i = 0;
    start = i;
    tmpKey = NULL;
    while(value[i] && (value[i] != '$' || is_space(value[i]) == false))
        i++;
    if(i > start)
    {
        tmpKey = (char *)malloc((sizeof(char) * (i - start)) + 1);
        ft_strncpy(tmpKey, value, (i - start));
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

// void    ft_expend(t_token *token, t_env **lst)
// {
//     int i;
//     int j;
// 	t_env *curVar;
//     char *tmpTokValue;

//     i = 0;
//     j = 0;
// 	curVar = *lst;
//     token->varTab = ft_split(token->value, ' ');
//     printf("=========== %s ===========\n", token->value);
//     tmpTokValue = valBefDol(token);
//     while(token->varTab[i] && char_search(token->varTab[i], '$') == true)
//     {
//         token->splitToD = exp_split(token->varTab[i], '$');
//         while (token->splitToD[j])
//         {
//             if(find_key_in_list(&curVar, token->splitToD[j]) == true)
//                 findVarEnv(&curVar, &tmpTokValue, token->splitToD[j]);
//             j++;
//         }
//         j = 0;
//         i++;
//     }
//     replaceToken(token, tmpTokValue);
//     printf("new token value %s\n", token->value);
//     printf("===============================\n");
//     free(tmpTokValue);
// }

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
            ft_expend(last, envVarlst, m_s);
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