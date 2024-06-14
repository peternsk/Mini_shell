/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:15:41 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:15:43 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_key(char *var)
{
	char	*look;

	look = ft_strchr(var, '=');
	if (look)
	{
		look++;
		if (ft_strlen(look) > 0)
			return (true);
	}
	return (false);
}
