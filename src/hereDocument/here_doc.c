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

int		count_here_doc(t_redlts **lst)
{
	t_redlts *tmp;
	int hereCount;

	tmp = *lst;
	hereCount = 0;
	while(tmp)
	{
		if(strcmp(tmp->redtype, "<<") == true)
			hereCount++;
		tmp = tmp->next;
	}
	return(hereCount);
}
void	empty_hereDoc(t_redlts *tmp)
{
	char *here_input;

	while(1)
	{
		here_input = readline(HERE_INPUT);
		if(delim_cmp(here_input, tmp->filename) == true)
			return;
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
		{
			printf(" HERE NBR [%d]\n", hereNbr);
			printf(" TMP ID [%d]\n", tmp->hereID);
			printf(" TMP DELIMITER [%s]\n", tmp->filename);
			printf(" IN EMPTY\n");
			empty_hereDoc(tmp);
		}
		if((delim_cmp(tmp->redtype, "<<") == true) && (tmp->hereID == hereNbr))
		{
			printf(" HERE NBR [%d]\n", hereNbr);
			printf(" TMP ID [%d]\n", tmp->hereID);
			printf(" TMP DELIMITER [%s]\n", tmp->filename);
			printf(" IN LAST\n");
			last_here_doc(m_s, tmp);
		}
		tmp = tmp->next;
	}
}
