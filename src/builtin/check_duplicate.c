/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:25:52 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/25 14:53:03 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int	check_same_(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	if (!s1)
		return (-1);
	if (!s2)
		return (-1);
	while (s1[i] && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char )s1[i] - (unsigned char )s2[i]);
		i++;
	}
	if (s2[i] == '\0' || i == n)
	{
		return (0);
	}
	else
		return (-s2[i]);
}
char **init_new(char **vars)
{
    char    **new;
    int     len;
    int     i;

    i = 0;
    len = size(vars);
    new =   malloc(sizeof(char *) * (len + 1));
    if (!new)
        return (new[len] = NULL, NULL);
    return (new);
}

char **check_duplicate(char **vars)
{
    char    **new;
    int     i;
    int     j;

    i = 0;
    j = 0;
    new = init_new(vars);
    if (!vars)
        return (NULL);
    i = 0;
    i++;
    while (vars[i] != NULL)
    {
        if (check_same_((const char *)vars[i], (const char *)vars[i + 1], ft_strlen((const char *)vars[i])) != 0)
        {
            new[j] = ft_strdup(vars[i]);
            j++;
        }
        i++;
    }
    new[j] = NULL;
    return (new);
}