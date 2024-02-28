/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:35:35 by peternsaka        #+#    #+#             */
/*   Updated: 2024/02/28 13:09:07 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_meta(char c)
{
	if(c == 60 || c == 62 || c == 124)
		return(true);
	return(false);
}

void	find_meta(t_minish *m_s)
{
	m_s->e = m_s->s;
	printf("4\n");
	sleep(1);
	create_token(m_s);
	m_s->s = m_s->e + 1;
}