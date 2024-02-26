/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:36:58 by pnsaka            #+#    #+#             */
/*   Updated: 2024/02/26 08:26:09 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*crt_str_tkn(void)
{
	t_token	*stru_tok;

	stru_tok = malloc(1 * sizeof(t_token));
	if (!stru_tok)
		return (NULL);
	stru_tok->prev = NULL;
	stru_tok->next = NULL;
	stru_tok->token_id = 0;
	stru_tok->type = 0;
	stru_tok->value = NULL;
	return (stru_tok);
}

t_minish *crt_str_ms(void)
{
	t_minish	*minish;

	minish = malloc(1 * sizeof(t_minish));
	if (!minish)
		return (NULL);
	minish->input = NULL;
	minish->index = 0;
    minish->s = 0;
    minish->e = 0;
	return(minish);
}
t_flags *crt_str_flag(void)
{
	t_flags	*flags;

	flags = malloc(1 * sizeof(t_flags));
	if (!flags)
		return (NULL);
    flags->sgl_flag = FLAG_OFF;
    flags->dbl_flag = FLAG_OFF;
    flags->wsp_flag = FLAG_OFF;
    flags->met_flag = FLAG_OFF;
    flags->otc_flag = FLAG_OFF;
    flags->flag_sw = FLAG_OFF;
	return(flags);
}
