/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:37:47 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/17 01:25:53 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool check_equal(char *var)
{
    char *look;

    look = ft_strchr(var, '=');
    if (look)
    {
        look++;
        if (ft_strlen(look) > 0)
            return (true);
    }
    return (false);
}
char    *pars_var(char *vars)
{
    int     i;
    char    *var_pars;
    
    i = 0;
    var_pars = malloc(sizeof(char *)  * (ft_strlen(vars)));
    if (!var_pars)
        return (NULL);
    while (vars[i] != '\0' || vars[i] != '=')
    {
        var_pars[i] = vars[i];
        i++;
    }
    var_pars[i] = '\0';
    // free(vars);
    return (var_pars);
}
int is_same_key(t_env *env, char *var)
{
    t_env   *node;
    int     i;

    node = env;
    i = 0;
    if (env && var && check_equal(var) == false)
    {
        printf("we enter\n");
        if (ft_strchr(var, '='))
            var = pars_var(var);
        while (node != NULL)
        {
            if (ft_strcmp(node->key, var) == false)
                node =  node->next;
            else
                return (i);
            i++;
        }   
        return (-1);
    }
    return (-3);
}