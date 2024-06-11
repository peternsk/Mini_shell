
#include "minishell.h"

t_cmdlts	*set_cmd_node(t_cmdlts *cmd, t_minish *m_s)
{
	cmd = malloc_and_add(sizeof(t_cmdlts));
	if (!cmd)
		return (0);
	cmd->prev = NULL;
	cmd->arr_len = -1;
	cmd->index = m_s->index;
	m_s->index = m_s->index + 1;
	cmd->command = (char **)malloc_and_add((sizeof(char *) * 150) + 1);
	if (!cmd->command)
		return (0);
	cmd->redlst = NULL;
	cmd->next = NULL;
	return (cmd);
}

void	add_cmd_node_to_end(t_cmdlts **lst, t_cmdlts *cmd)
{
	t_cmdlts	*last;

	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = cmd;
		cmd->next = NULL;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = cmd;
	cmd->prev = last;
}

int	ft_nbr_of_node(t_token **lst)
{
	t_token	*last;
	int		node_needed;

	last = *lst;
	node_needed = 1;
	while (last != NULL)
	{
		if (last->type == pipe_)
			node_needed++;
		last = last->next;
	}
	return (node_needed);
}

void	print_array(char **arr)
{
	int	i;

	i = 0;
	// printf("========== command ============\n");
	while (arr[i])
	{
		// printf("%s\n", arr[i]);
		// printf("_______________________________\n");
		i++;
	}
	// printf("===============================\n");
}

void	print_comd_lst(t_cmdlts **lst)
{
	t_cmdlts	*last;
	int			i;

	last = *lst;
	i = 0;
	// if (last == NULL)
	// 	printf("= empty list\n");
	// while (last != NULL)
	// {
	// 	printf("============= CMD =============\n");
	// 	printf("= " GRN "command prev  : %p" RESET " \n", last->prev);
	// 	printf("= command id    : " YEL "%d" RESET " \n", last->index);
	// 	while (last->command[i] != NULL)
	// 	{
	// 		printf("= argument[%d]   :" BLU " %s" RESET "         \n", i,
	// 			last->command[i]);
	// 		i++;
	// 	}
	// 	printf("= argument[%d]   :" BLU " %s" RESET "         \n", i,
	// 		last->command[i]);
	// 	printf("= " GRN "command next  : %p" RESET " \n", last->next);
	// 	print_red_lst(&last->redlst);
	// 	printf("===============================\n");
	// 	printf("                 =\n");
	// 	printf("                 =\n");
	// 	i = 0;
	// 	last = last->next;
	// }
}

void	ft_createcomd_lst(t_minish *m_s)
{
	t_cmdlts	*cmd;
	int			nb_of_node;

	cmd = NULL;
	m_s->index = 0;
	nb_of_node = ft_nbr_of_node(&m_s->token_lst);
	while (nb_of_node > 0)
	{
		add_cmd_node_to_end(&m_s->comd_lst, set_cmd_node(cmd, m_s));
		nb_of_node--;
	}
}
