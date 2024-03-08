/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findVarEnv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:22:54 by pnsaka            #+#    #+#             */
/*   Updated: 2024/03/08 10:37:08 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool    char_search(char *tok_value, char c)
{
    int i;

    i = 0;
    while(tok_value[i])
    {
        if(tok_value[i] == c)
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

char    *find_key_in_list(t_env **lst, char *tmpKey, char *tmpValue)
{
    t_env *current;

    current = *lst;
    while(current != NULL)
    {
        if(ft_strcmp(tmpKey, current->key) == true)
        {
            tmpValue = ft_strdup(current->value);
            return(tmpValue);
        }
        current = current->next;
    }
    return(tmpValue);
}

void    ft_expend(char *str)
{
    int i;
    int j;
    char **var_tab;
    char **split_dolla;

    i = 0;
    j = 0;
    var_tab = ft_split(str, ' ');
    printf("=========== EXP TAB ===========\n");
    while(var_tab[i] && char_search(var_tab[i], '$') == true)
    {
        printf("%s\n", var_tab[i]);
        printf("-------------------------------\n");
        split_dolla = exp_split(var_tab[i]);
        while (split_dolla[j])
        {
            printf(" === %s ===\n", split_dolla[j]);
            j++;
        }
        j = 0;
        i++;
    }
    printf("===============================\n");
    printf("                 =\n");
	printf("                 =\n");
}

void	print_expendTab(t_token *lst)
{
	t_token *last;
	
	last = lst;
	if(last == NULL)
		printf("empty list\n");
	while(last != NULL)
	{
        if((last->type == argument || last->type == dbl_quote_arg) && (char_search(last->value, '$') == true))
            ft_expend(last->value);
		last = last->next;
	}
}