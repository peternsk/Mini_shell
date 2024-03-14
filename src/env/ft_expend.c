/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:48:25 by pnsaka            #+#    #+#             */
/*   Updated: 2024/03/13 20:49:21 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_expend(t_token *token, t_env **lst, t_minish *m_s)
{
    // char *expStr;
    // char *tmpKey;
    (void)lst;
    
    m_s->e = 0;
    m_s->s = 0;
    while(token->value[m_s->e] && token->value[m_s->e] != '$')
        m_s->e++;
    printf("m_s->e : %d\n", token->value[m_s->e]);
    printf("char[ %c ]\n", token->value[m_s->e]);
}