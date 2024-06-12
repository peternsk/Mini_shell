/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:28:26 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:28:28 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_char_in_set(char c, char const *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_trim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;
	size_t	str_size;

	start = 0;
	if (!s1 || !set)
		return (0);
	end = ft_strlen(s1);
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	while (end > start && ft_char_in_set(s1[end - 1], set))
		end--;
	str_size = (end - start + 1);
	str = (char *)malloc_and_add(str_size * sizeof(*s1));
	if (!str)
		return (0);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
