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

// void	check_here_doc(t_minish *m_s, t_redlts **lst)
// {
// 	t_redlts *tmp;
// 	char *here_input;

// 	tmp = *lst;
// 	while(tmp)
// 	{
// 		if(delim_cmp(tmp->redtype, "<<") == true)
// 		{
// 			while(1 && tmp->next)
// 			{
// 				// printf("DELIMITER [%s]\n", tmp->filename);
// 				here_input = readline(HERE_INPUT);
// 				if(delim_cmp(here_input, tmp->filename) == true)
// 				{
// 					print_here_lst(m_s->herelst);
// 					return;
// 				}
// 				else
// 					create_here_lst(m_s, here_input);
// 			}
// 			tmp = tmp->next;
// 		}
// 		tmp = tmp->next;
// 	}
// 	print_here_lst(m_s->herelst);
// }

void input_usr(t_minish *m_s, t_files *tmp)
{
	char *here_input;

	tmp->made = -1;
	while (true)
	{
		here_input = readline(HERE_INPUT);
		if(delim_cmp(here_input, tmp->name) == true)
		{
			// print_here_lst(m_s->herelst);
			// clean the everything;
			// and also put everything in the last <<;
			// and also put everything in the last <<;
			// not to forget to close the fd 
			return;
		}
		else if (here_input == NULL)
			// clean verything 
			return ;
		else
			create_here_lst(m_s, here_input);
	}
}

void	check_here_doc(t_minish *m_s, t_files **lst)
{
	t_files *tmp;
	

	tmp = *lst;
	// while(tmp)
	// {
		// tu check if il y un file 
		if (tmp)
		{
			// tu check le type de file 
			// if(delim_cmp(tmp->type, "<<") == true)
			// {
				// tu vas regarde s'il y a plusieur file si c'est le cas tu va regarde le type puis le faire le << sans le mettre dans le file 
				while(tmp->next != NULL && tmp->type == here_doc && tmp->made == 0)
				{
					// printf("DELIMITER [%s]\n", tmp->filename);
					// tu prend le usr inpute 
					// input_usr(m_s, tmp);
					tmp = tmp->next;
				}
				// si c'est le seul << dans le file tu vas le faire 
				if (tmp->next == NULL && tmp->type == here_doc && tmp->made == 0)
					input_usr(m_s, tmp);
			// }
			// tmp = tmp->next;
		}
	// }
	print_here_lst(m_s->herelst);
}

void	empty_hereDoc(t_redlts *tmp)
{
	char *here_input;

	while(1)
	{
		here_input = readline(HERE_INPUT);
		if(delim_cmp(here_input, tmp->filename) == true)
			return;
		// else
		// 	printf(" >%s\n", here_input);
	}
}

void	last_here_doc(t_minish *m_s, t_redlts *tmp)
{
	char *here_input;

	while(1)
	{
		here_input = readline(HERE_INPUT);
		if(delim_cmp(here_input, tmp->filename) == true)
			return;
		else
			create_here_lst(m_s, here_input);
	}
}

void	run_here_redlst(t_minish *m_s, t_redlts **lst)
{
	t_redlts *tmp;
	int hereNbr;

	tmp = *lst;
	hereNbr = count_here_doc(lst);
	while(tmp)
	{
		if((delim_cmp(tmp->redtype, "<<") == true) && (tmp->hereID < hereNbr))
			empty_hereDoc(tmp);
		if((delim_cmp(tmp->redtype, "<<") == true) && (tmp->hereID == hereNbr))
			last_here_doc(m_s, tmp);
		tmp = tmp->next;
	}

}