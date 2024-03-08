/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:18:42 by pnsaka            #+#    #+#             */
/*   Updated: 2024/03/08 13:10:54 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**exp_split(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int wc = 0;
	while (str[i])
	{
        while (str[i] && (str[i] != '$'))
			i++;
		if (str[i] == '$')
        {
			wc++;
            i++;
        }
	}
	char **out = (char **)malloc(sizeof(char *) * (wc + 1));
	if(!out)
		return(0);
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] != '$'))
		    i++;
		j = ++i;
    	printf("j = idx %d\n", j);
		while (str[i] && (str[i] != '$'))
			i++;
    	printf("i = idx %d\n", i);
		if (i > j)
		{
    			printf("\n");
				out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
				ft_strncpy(out[k++], &str[j], i - j);
        	    printf("%s\n", out[k++]);
		}
	}
	out[k] = NULL;
	return (out);
}
