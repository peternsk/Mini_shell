/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:20:31 by peternsaka        #+#    #+#             */
/*   Updated: 2024/02/26 21:17:53 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		main(int ac, char **av)
{
	t_minish *minish;
	(void)av;

	if(ac > 0)
	{
		ft_ascii_font();
		minish = init_ms();
		minish->flags = init_flag();
		minish->input = readline(INPUT);
		printf("the command is : %s\n", minish->input);
		tokenizer(minish);
	}
	else
		printf("arg missing !!\n");
}