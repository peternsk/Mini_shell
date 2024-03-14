/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:48:25 by pnsaka            #+#    #+#             */
/*   Updated: 2024/03/14 14:10:53 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_expend(t_token *token, t_env **lst, t_minish *m_s)
{
    // char *expStr;
    // char *tmpKey;
    (void)lst;
    
    int s;
    int e;

    s = 0;
    e = 0;
    while(token->value[e] && token->value[e] != '$')
        m_s->e++;
    printf("m_s->e : %d\n", e);
    printf("m_s->s : %d\n", s);
    printf("char[ %c ]\n", token->value[e]);
}