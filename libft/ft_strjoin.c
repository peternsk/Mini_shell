/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:17:06 by peternsaka        #+#    #+#             */
/*   Updated: 2022/11/29 16:52:43 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	new_str_len;
	char	*new_str;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (0);
	new_str_len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	new_str = (char *)malloc(new_str_len * sizeof(char));
	if (!new_str)
		return (new_str);
	while (s1[++i])
		new_str[i] = s1[i];
	while (s2[++j])
		new_str[i++] = s2[j];
	new_str[i] = 0;
	return (new_str);
}
