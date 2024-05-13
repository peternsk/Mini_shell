#include "minishell.h"

void handel()
{
	// function mal need to be fix
    printf("hello from the parent");
	printf("\n");
}
void	handel_childs()
{
    printf("hello from the childs -- -- \n");
	return ;
}
void nothing(){ printf("say my name ... \n");}

void manage_signal (int id)
{
	if (id == 0)
	{
		signal(SIGINT, handel_childs);
		signal(SIGQUIT, handel_childs); 
	}
	else
	{
		signal(SIGINT, handel);
		signal(SIGQUIT, nothing); 
	}
}
