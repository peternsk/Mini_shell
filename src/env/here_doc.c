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