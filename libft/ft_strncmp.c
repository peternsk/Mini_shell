/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:57:47 by pnsaka            #+#    #+#             */
/*   Updated: 2024/03/07 23:20:43 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = -1;
	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (0);
	while ((s1[++i] || s2[i]) && \
		(s1[i] == s2[i]) && (i < n - 1))
		;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
