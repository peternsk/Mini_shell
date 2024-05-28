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

void	check_here_doc(t_minish *m_s, t_files **lst)
{
	t_files *tmp;
	char *here_input;

	tmp = *lst;
	while(tmp)
	{
		if(tmp->type == here_doc)
		{
			while(1 && tmp->next)
			{
				here_input = readline(HERE_INPUT);
				if(delim_cmp(here_input, tmp->name) == true)
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

void	empty_hereDoc(t_files *tmp)
{
	printf("in empty\n");
	char *here_input;
	if (tmp->made == 0)
	{
		tmp->made = -1;
		while(1)
		{
			here_input = readline(HERE_INPUT);
			if(delim_cmp(here_input, tmp->name) == true)
				return;
		}
	}
}

// void	last_here_doc(t_minish *m_s, t_files *tmp)
// {
// 	char *here_input;

// 	while(1)
// 	{
// 		here_input = readline(HERE_INPUT);
// 		if(delim_cmp(here_input, tmp->name) == true)
// 			return;
// 		else
// 			create_here_lst(m_s, here_input);
// 	}
// }

void	last_here_doc(t_cmd *cmd)
{
	char *here_input;

	printf("in last\n");
	while(1)
	{
		here_input = readline(HERE_INPUT);
		if(delim_cmp(here_input, cmd->files->name) == true)
			return;
		else
			create_here_lst(cmd->glob, here_input);
	}
}

int		count_here_doc(t_files **lst)
{
	int i;
	t_files *tmp;

	i = 0;
	tmp = *lst;
	while(tmp)
	{
		if(tmp->type == here_doc)
			i++;
		tmp = tmp->next;
	}
	return(i);
}

// void	run_here_redlst(t_minish *m_s, t_files **lst)
// {
// 	t_files *tmp;
// 	int hereNbr;

// 	tmp = *lst;
// 	hereNbr = count_here_doc(lst);
// 	while(tmp)
// 	{
// 		if((tmp->type == here_doc) && (tmp->hereID < hereNbr))
// 			empty_hereDoc(tmp);
// 		if((tmp->type == here_doc) && (tmp->hereID == hereNbr) && tmp->made == 0)
// 		{
// 			tmp->made = -1;
// 			tmp->manage_fd = dup(0);
// 			last_here_doc(m_s, tmp);
// 			send_2_tmp(&m_s->herelst, m_s);
// 		}
// 		tmp = tmp->next;
// 	}
// }

void	run_here_redlst(t_cmd *cmdlst)
{
	t_cmd *tmp;
	int hereNbr;

	tmp = cmdlst;
	hereNbr = count_here_doc(&tmp->files);
	printf("here nbr [%d]\n", hereNbr);
	while(tmp->files)
	{
		printf("in cmd [%d]\n", tmp->index);
		printf("here id [%d]\n", tmp->files->hereID);
		if((tmp->files->type == here_doc) && (tmp->files->hereID < hereNbr))
			empty_hereDoc(tmp->files);
		if((tmp->files->type == here_doc) && tmp->files->made == 0)
		{
			tmp->files->made = -1;
			tmp->files->manage_fd = dup(0);
			last_here_doc(tmp);
			send_2_tmp(&tmp->glob->herelst, tmp->glob, tmp->index);
			// free_here_list(&tmp->glob->herelst);
			// return;
		}
		tmp->files = tmp->files->next;
	}
}
