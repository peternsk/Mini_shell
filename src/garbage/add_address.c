
#include "minishell.h"

t_garbage	*get_head(void)
{
	static struct s_garbage	garb_coll = {0, 0};

	return (&garb_coll);
}

void	*malloc_and_add(size_t size)
{
	t_garbage	*node;

	node = malloc(sizeof(t_garbage));
	if (!node)
		return (0);
	node->adresse = malloc(size);
	if (!node->adresse)
	{
		free(node);
		return (0);
	}
	node->next = get_head()->next;
	get_head()->next = node;
	return (node->adresse);
}

void	add_garbage(void *adresse)
{
	t_garbage	*node;

	node = malloc(sizeof(t_garbage));
	if (!node)
		return ;
	node->adresse = adresse;
	node->next = get_head()->next;
	get_head()->next = node;
}

void	all_free(void)
{
	t_garbage	*gc_ptr;
	t_garbage	*tmp;

	gc_ptr = get_head()->next;
	while (gc_ptr)
	{
		if (gc_ptr->adresse)
		{
			free(gc_ptr->adresse);
			gc_ptr->adresse = NULL;
		}
		tmp = gc_ptr;
		gc_ptr = gc_ptr->next;
		if (tmp)
		{
			free(tmp);
			tmp = NULL;
		}
	}
	get_head()->next = NULL;
}

void	add_garbage_arr(char **arr)
{
	int	i;

	i = 0;
	add_garbage(arr);
	while (arr[i])
	{
		add_garbage(arr[i]);
		i++;
	}
}

void	print_garbage_collector(void)
{
	t_garbage	*last;
	int			i;

	i = 0;
	last = get_head()->next;
	if (last == NULL)
		printf("empty list\n");
	while (last != NULL)
	{
		printf("                 =\n");
		printf("                 =\n");
		printf("========== GARLST =============\n");
		printf("= garbage addy  : %p           \n", last->adresse);
		printf("= garbage next  : %p           \n", last->next);
		printf("===============================\n");
		printf("                 =\n");
		printf("                 =\n");
		i++;
		last = last->next;
	}
	printf("========= GARNODES ============\n");
	printf("= num of nodes  : %d           \n", i);
	printf("===============================\n");
}
