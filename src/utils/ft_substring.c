/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:40:31 by pnsaka            #+#    #+#             */
/*   Updated: 2024/03/06 09:42:30 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_substring(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub_str;

	if (!s)
		return (0);
	i = 0;
	if (start < ft_strlen_(s))
		while (i < len && s[start + i])
				i++;
	sub_str = (char *)malloc((i + 1) * sizeof(*s));
	if (!sub_str)
		return (sub_str);
	i = 0;
	if (start <= ft_strlen_(s))
	{
		while (i < len && s[start] != '\0')
		{
			sub_str[i] = s[start];
			start++;
			i++;
		}
	}
	sub_str[i] = '\0';
	return (sub_str);
}