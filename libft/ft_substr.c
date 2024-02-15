/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:07:28 by peternsaka        #+#    #+#             */
/*   Updated: 2022/11/30 12:21:20 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub_str;

	if (!s)
		return (0);
	i = 0;
	if (start < ft_strlen(s))
		while (i < len && s[start + i])
				i++;
	sub_str = (char *)malloc((i + 1) * sizeof(*s));
	if (!sub_str)
		return (sub_str);
	i = 0;
	if (start <= ft_strlen(s))
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
