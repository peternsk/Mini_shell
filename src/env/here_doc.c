#include "minishell.h"

void	check_here_doc(t_redlts **lst)
{
	t_redlts *tmp;

	tmp = *lst;
	while(tmp)
	{
		if(delim_cmp(tmp->redtype, "<<"))
			ft_here_doc(tmp);
		tmp = tmp->next;
		printf("NEXT TMP\n");
	}
	return;
}

void	ft_here_doc(t_redlts *redNode)
{
	char *here_input;

	while(1)
	{
		printf("delimiter : %s\n", redNode->filename);
		here_input = readline(HERE_INPUT);
		if(delim_cmp(here_input, redNode->filename) == true)
			break;
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