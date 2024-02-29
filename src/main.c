/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:20:31 by peternsaka        #+#    #+#             */
/*   Updated: 2024/02/29 11:52:57 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		main(int ac, char **av)
{
	t_minish *minish;
	(void)av;

	ft_ascii_font();
	if(ac > 0)
	{
		while(1)
		{
			minish = init_ms();
			minish->flags = init_flag();
			minish->input = readline(INPUT);
			add_history(minish->input);
			tokenizer(minish);
			print_token(minish->token_lst);
			printf("========= list size %d =========\n", count_token(minish->token_lst));
		}
	}
	else
		printf("arg missing !!\n");
}
