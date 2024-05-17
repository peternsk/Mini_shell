/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printEnvp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:19:46 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/05/17 12:00:59 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strncmp_envp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (s1[i] && i < n)
	{
		if (s1[i] != s2[i])
        {
            if (s1[i] > s2[i])
                return (2);
            return (1);
        }
		i++;
	}
	if (s2[i] == '\0' || i == n)
		return (1);
	else
		return (-s2[i]);
}
int len_envp(char **array)
{
    int i;

    i = 0;
    if (array)
        while (array[i] != NULL)
            i++;   
    return (i);
}
void    swap(char **s1, char **s2)
{
    char *tmp;

    tmp = NULL;
    tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;

}

void ft_sort(char **envp)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (envp)
    {
        while (envp[i] != NULL)
        {
            j = i + 1;
            while (envp[j] != NULL)
            {
                if (ft_strncmp_envp(envp[i], envp[j],  ft_strlen(envp[j])) == 2)
                    swap(&envp[i], &envp[j]);
                j++;
            }
            i++;
        }
    }
}
 
void    printEnvp(char **envp)
{
    int i;

    i = 0;
    printf("len array %d\n", len_envp(envp));
    ft_sort(envp);
    while (envp[i]!= NULL){
        printf("declare -x %s\n", envp[i]);
        i++;
    }
}