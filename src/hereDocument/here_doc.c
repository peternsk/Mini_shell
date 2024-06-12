/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:21:20 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/11 20:53:44 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	delim_cmp(char *input, char *delimiter)
{
	int	i;

	i = 0;
	if (ft_strlen(input) != ft_strlen(delimiter))
		return (false);
	while (input[i] != '\0')
	{
		if (input[i] == delimiter[i])
			i++;
		else
			return (false);
	}
	return (true);
}

void	check_here_doc(t_minish *m_s, t_files **lst)
{
	t_files	*tmp;
	char	*here_input;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->type == here_doc)
		{
			while (1 && tmp->next)
			{
				here_input = readline(HERE_INPUT);
				if (delim_cmp(here_input, tmp->name) == true)
				{
					return ;
				}
				else
					create_here_lst(m_s, here_input);
			}
			tmp = tmp->next;
		}
		tmp = tmp->next;
	}
}

void	empty_heredoc(t_files *tmp)
{
	char	*here_input;

	if (tmp->made == 0)
	{
		tmp->made = -1;
		while (1)
		{
			here_input = readline(HERE_INPUT);
			if (delim_cmp(here_input, tmp->name) == true)
				return ;
		}
	}
}

void	last_here_doc(t_minish *m_s, t_files *tmp)
{
	char	*here_input;

	while (1)
	{
		here_input = readline(HERE_INPUT);
		if (delim_cmp(here_input, tmp->name) == true)
			return ;
		else
			create_here_lst(m_s, here_input);
	}
}

int	count_here_doc(t_files **lst)
{
	int		i;
	t_files	*tmp;

	i = 0;
	tmp = *lst;
	while (tmp)
	{
		if (tmp->type == here_doc)
			i++;
		tmp = tmp->next;
	}
	return (i);
}
