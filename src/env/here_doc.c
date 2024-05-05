#include "minishell.h"

void	ft_here_doc(t_redlts **lst)
{
	t_redlts *tmp;

	tmp = *lst;
	while(tmp)
	{
		if(tmp->redtype == here_doc)
			printf("GOT TO DO THE HERE DOC FUNCTION\n");
		tmp = tmp->next;
	}
}