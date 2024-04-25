/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:35:15 by pnsaka            #+#    #+#             */
/*   Updated: 2024/04/25 19:34:12 by mnshimiy         ###   ########.fr       */
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
    if(!str)
        return(0);
    i = -1;
    while(tmp->key[++i])
        str[i] = tmp->key[i];
    str[i] = '=';
    i++;
    j = -1;
    while(tmp->value && tmp->value[++j])
    {
        str[i] = tmp->value[j];
        i++;
    }
    str[i] = '\0';
    return(str);
}


char    **list_to_tab(t_env **lst)
{
    int nb_token;
    t_env *node;
    char **env_tab;
	int i;

    node = *lst;
    nb_token = count_env_node(node);
    env_tab = (char**)malloc((sizeof(char *) * nb_token) + 1);
    if (!env_tab)
        return (NULL);
	i = -1;
    while(++i < nb_token && node)
    {
        env_tab[i] = token_2_str(node);
        node = node->next;
    }
    env_tab[--i] = NULL;
    return(env_tab);
}

