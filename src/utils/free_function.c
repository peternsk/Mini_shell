
#include "minishell.h"

void	free_list(t_token **list)
{
	t_token	*tmp;

	if (list)
	{
		while (*list != NULL)
		{
			tmp = (*list)->next;
			free(*list);
			(*list) = tmp;
		}
		*list = NULL;
	}
}

void	free_tabl(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}