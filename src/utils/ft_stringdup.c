/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:21:06 by pnsaka            #+#    #+#             */
/*   Updated: 2024/03/06 09:38:28 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_stringdup(const char *s1)
{
	int		i;
	char	*dest;
	int		len;

	if (!s1)
		return (0);
	len = ft_strlen_(s1) + 1;
	i = 0;
	dest = (char *)malloc(len * sizeof(char));
	if (dest == 0)
	{
		return (0);
	}
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
