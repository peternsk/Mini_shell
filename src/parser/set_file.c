
#include "minishell.h"

void	set_delimiter(t_token **lst)
{
	t_token	*cur;

	cur = *lst;
	while (cur != NULL)
	{
		if (cur->type == here_doc && cur->next != NULL)
		{
			cur = cur->next;
			if (cur->type == argument)
				cur->type = delimter;
		}
		cur = cur->next;
	}
}

void	set_file_red(t_token **lst)
{
	t_token	*cur;

	cur = *lst;
	while (cur != NULL)
	{
		if ((cur->type == here_doc || cur->type == APOR || cur->type == OPR
				|| cur->type == IPR) && cur->next != NULL)
		{
			cur = cur->next;
			if (cur->type == argument)
				cur->type = _file;
		}
		cur = cur->next;
	}
}
