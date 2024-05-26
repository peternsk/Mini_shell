

#include "minishell.h"

static char	**free_tab(char **exp_tab)
{
	size_t	i;

	i = 0;
	while (exp_tab[i])
	{
		free(exp_tab[i]);
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
	while ((str[i] != c) && str[i])
			i++;
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
	while ((s[i] != c) && s[i])
			i++;
	while (s[i] && word < count_word(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		split[word] = ft_substr(s, start, i - start);
		if (!split[word])
			return (free_tab(split));
		add_garbage(split[word]);
		word++;
	}
	split[word] = 0;
	return (split);
}

char	**exp_split(char const *s, char c)
{
	char	**split;
	size_t	nbw;

	if (!s)
		return (0);
	nbw = count_word(s, c);
	split = malloc_and_add(sizeof(char *) * (nbw + 1));
	if (!split)
		return (0);
	return (splitcpy(split, s, c));
}
