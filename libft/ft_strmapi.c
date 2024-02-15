/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:06:41 by pnsaka            #+#    #+#             */
/*   Updated: 2022/12/06 14:51:36 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*s_dup;

	if (!s)
		return (0);
	i = -1;
	s_dup = (char *)malloc((ft_strlen(s) * sizeof(char) + 1));
	if (!s_dup)
		return (s_dup);
	while (s[++i])
		s_dup[i] = (*f)(i, s[i]);
	s_dup[i] = '\0';
	return (s_dup);
}
