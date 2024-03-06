/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envSplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:00:11 by pnsaka            #+#    #+#             */
/*   Updated: 2024/03/06 09:42:08 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**free_tab(char **tabl)
{
	size_t	i;

	i = 0;
	while (tabl[i])
	{
		free(tabl[i]);
		i++;
	}
	return (0);
}

static size_t	count_word(char const *str, char c)
{
	size_t	i;
	size_t	nbw;

	i = 0;
	nbw = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		while ((str[i] == c) && str[i])
			i++;
		while ((str[i] != c) && str[i])
			i++;
		if (str[i - 1] != c)
			nbw++;
	}
	return (nbw);
}

static char	**splitcpy(char **split, char const *s, char c)
{
	size_t	word;
	size_t	i;
	size_t	start;

	i = 0;
	word = 0;
	while (s[i] && word < count_word(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		split[word] = ft_substring(s, start, i - start);
		if (!split[word])
			return (free_tab(split));
		word++;
	}
	split[word] = 0;
	return (split);
}

char	**ft_envSplit(char const *s, char c)
{
	char	**split;
	size_t	nbw;

	if (!s)
		return (0);
	nbw = count_word(s, c);
	split = malloc(sizeof(char *) * (nbw + 1));
	if (!split)
		return (0);
	return (splitcpy(split, s, c));
}