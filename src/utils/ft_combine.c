/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:27:47 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:27:49 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_combine(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*comb_str;

	i = -1;
	j = -1;
	comb_str = (char *)malloc_and_add(sizeof(char) * (ft_strlen(s1)
				+ ft_strlen(s2)) + 1);
	if (!comb_str)
		return (0);
	while (s1[++i])
		comb_str[i] = s1[i];
	while (s2[++j])
	{
		comb_str[i] = s2[j];
		i++;
	}
	comb_str[i] = '\0';
	return (comb_str);
}
