/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:20:31 by peternsaka        #+#    #+#             */
/*   Updated: 2024/02/27 09:56:25 by pnsaka           ###   ########.fr       */
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
			printf("the command is : %s\n", minish->input);
			tokenizer(minish);
		}
	}
	else
		printf("arg missing !!\n");
}
