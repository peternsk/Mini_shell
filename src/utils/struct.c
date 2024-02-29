/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:36:58 by pnsaka            #+#    #+#             */
/*   Updated: 2024/02/28 15:36:10 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_minish *init_ms(void)
{
	t_minish	*minish;

	minish = malloc(1 * sizeof(t_minish));
	if (!minish)
		return (NULL);
	minish->input = NULL;
	minish->token_lst = NULL;
	minish->index = 0;
    minish->s = 0;
    minish->e = 0;
	return(minish);
}
t_flags *init_flag(void)
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
	flags->found_flag = FLAG_OFF;
    flags->flag_sw = FLAG_OFF;
	return(flags);
}
