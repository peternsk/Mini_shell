/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:59:20 by pnsaka            #+#    #+#             */
/*   Updated: 2022/11/29 17:52:05 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (!haystack || !needle)
		return (0);
	i = 0;
	if (needle[i] == 0)
		return ((char *)haystack);
	if (ft_strlen(needle) > ft_strlen(haystack))
		return (0);
	while (haystack[i] && i < len)
	{
		j = 0;
		if ((char)haystack[i] == (char)needle[j])
		{
			while ((char)haystack[i + j] == (char)needle[j] && (i + j) < len)
			{
				j++;
				if (needle[j] == '\0')
					return ((char *)haystack + i);
			}
		}
		i++;
	}
	return (0);
}
