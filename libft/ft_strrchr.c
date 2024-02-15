/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:23:58 by pnsaka            #+#    #+#             */
/*   Updated: 2022/11/29 17:58:53 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = ft_strlen(s) + 1;
	while (--i >= 0)
		if (s[i] == (char)c)
			return ((char *)s + i);
	if (c == '\0')
		return ((char *)s + i);
	return (0);
}
