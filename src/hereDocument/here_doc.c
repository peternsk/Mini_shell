#include "minishell.h"

bool    delim_cmp(char *input, char *delimiter)
{
    int i;

    i = 0;
    if(ft_strlen(input) != ft_strlen(delimiter))
        return(false);
    while(input[i] != '\0')
    {
        if(input[i] == delimiter[i])
            i++;
        else
            return(false);
    }
    return(true);
}

void	check_here_doc(t_minish *m_s, t_redlts **lst)
{
	t_redlts *tmp;
	char *here_input;

	tmp = *lst;
	while(tmp)
	{
		if(delim_cmp(tmp->redtype, "<<") == true)
		{
			while(1 && tmp->next)
			{
				// printf("DELIMITER [%s]\n", tmp->filename);
				here_input = readline(HERE_INPUT);
				if(delim_cmp(here_input, tmp->filename) == true)
				{
					print_here_lst(m_s->herelst);
					return;
				}
				else
					create_here_lst(m_s, here_input);
			}
			tmp = tmp->next;
		}
		tmp = tmp->next;
	}
	print_here_lst(m_s->herelst);
}
