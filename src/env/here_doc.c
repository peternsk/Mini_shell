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

void	check_here_doc(t_redlts **lst)
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
				printf("DELIMITER [%s]\n", tmp->filename);
				here_input = readline(HERE_INPUT);
				if(delim_cmp(here_input, tmp->filename) == true)
					return;
				else
					printf("ADD TO FILE\n");
			}
		}
		tmp = tmp->next;
	}
	return;
}


/*
	c'est la representation d'une linked list de redirection qu'on trouve dans une node de commande que je domme a l'execution.
	l'objectif va etre de passer a traver et de trouver une here document et de lancer la function qui va permetre de creer un fichier
	tempopraire qui va etre traiter par la command en cas de besoin.

			###########			###########			###########			###########			###########			###########
	<=======#         # <====== #		  # <====== #         # <====== #		  # <====== #		  # <====== #		  #
			#	<<	  *			#	 >	  *			#	<<	  *			#	 >	  *			#	<<	  *			#	 >	  *
			#		  *			#		  *			#		  *			#		  *			#		  *			#		  *
			#	EOF	  *			#	fil	  *			#	EOF	  *			#	fil	  *			#	EOF	  *			#	fil	  *
			#         # ======> #		  # ======> #         # ======> #		  # ======> #		  # ======> #		  # ======>
			###########			###########			###########			###########			###########			###########

				#					#					#					#					#					#
				#					#					#					#					#					#
				#					#					#					#					#					#

			###########			###########			###########			###########			###########			###########
			#         # 		#		  # 		#         # 		#		  # 		#		  # 		#		  #
			#		  *			#		  *			#		  *			#		  *			#		  *			#		  *
			#	tmp	  *	===>	#	rel	  *			#	tmp	  *	===>	#	rel	  *			#	tmp	  *	===>	#	rel	  *
			#	fil	  *			#	fil	  *			#	fil	  *			#	fil	  *			#	fil	  *			#	fil	  *
			#         # 		#		  # 		#         # 		#		  # 		#		  # 		#		  # 		
			###########			###########			###########			###########			###########			###########



*/