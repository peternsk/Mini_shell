/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:18:42 by pnsaka            #+#    #+#             */
/*   Updated: 2024/03/08 11:08:17 by pnsaka           ###   ########.fr       */
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
            printf(" word count %d\n", wc);
            printf(" idx %d\n", i);
        }
	}
	char **out = (char **)malloc(sizeof(char *) * (wc + 1));
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] != '$'))
		    i++;
		j = i;
		while (str[i] && (str[i] != '$'))
			i++;
		if (i > j)
		{
			out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(out[k++], &str[j], i - j);
            printf("%s\n", out[k++]);
		}
	}
	out[k] = NULL;
	return (out);
}