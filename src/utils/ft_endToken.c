/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endToken.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:28:24 by pnsaka            #+#    #+#             */
/*   Updated: 2024/04/03 13:38:58 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_endToken(t_token *token, t_minish *m_s)
{   
	if(m_s->input[m_s->e + 1] == ' ' || m_s->input[m_s->e + 1] == '\0')
    {
        token->endToken = FLAG_ON;
        token->to_merge = FLAG_OFF;
    }
    else if(m_s->input[m_s->e] && m_s->input[m_s->e + 1] && m_s->input[m_s->e + 1] == ' ')
    {
        token->endToken = FLAG_ON;
        token->to_merge = FLAG_ON;
    }
    else
    {
        token->endToken = FLAG_OFF;
        token->to_merge = FLAG_ON;
    }
}
