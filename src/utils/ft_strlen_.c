/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:47:11 by peternsaka        #+#    #+#             */
/*   Updated: 2024/02/29 17:51:04 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen_(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
		;
	return (i);
}