/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:35:15 by pnsaka            #+#    #+#             */
/*   Updated: 2024/04/17 15:40:02 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int		count_env_node(t_env *node)
{
	int nb_token;

	nb_token = 0;
	while(node != NULL)
	{
		nb_token++;
		node = node->next;
	}
	return(nb_token);
}

char    *token_2_str(t_env *env_node)
{
    char *str;
    t_env *tmp;
    int i;
    int j;
    
    tmp = env_node;
    str = (char *)malloc((sizeof(char) * (ft_strlen(tmp->key) + ft_strlen(tmp->value))) + 2);
    i = -1;
    while(tmp->key[++i])
        str[i] = tmp->key[i];
    str[i] = '=';
    i++;
    j = -1;
    while(tmp->value[++j])
    {
        str[i] = tmp->value[j];
        i++;
    }
    str[i] = '\0';
    return(str);
}


char    **list_to_tab(t_env **lst)
{
    size_t nb_token;
    t_env *node;
    char **env_tab;

    node = *lst;
    nb_token = count_env_node(node);
    env_tab = (char**)malloc((sizeof(char *) * nb_token) + 1);
    printf("tap [%p]\n", &env_tab);
    while(node)
    {
        *env_tab = token_2_str(node);
        printf("str [%s]\n", *env_tab);
        printf("add str [%p]\n", &env_tab);
        env_tab+1;
        printf("add str 2 [%p]\n", &env_tab);
        node = node->next;
    }
    env_tab = NULL;
    printf("tap [%p]\n", &env_tab);
    return(env_tab);
}

