#ifndef GARBAGE_H
#define GARBAGE_H

/*====================================================*/
/*=                     STRUCTURE                    =*/
/*====================================================*/
typedef struct s_garbage
{
	void	*adresse;
	struct s_garbage *next;
} t_garbage;

/*====================================================*/
/*=                     FUNCTIONS                    =*/
/*====================================================*/

/*--- ADDING NODE TO THE GARBAGE LINKED LIST ---*/

t_garbage 	*get_head(void);
void		*malloc_and_add(size_t size);
void		add_garbage(void *adresse);
void		add_garbage_arr(char **arr);

/*--- DELETING NODE TO THE GARBAGE LINKED LIST ---*/
void		all_free(void);
void 		free_list_garb(t_garbage **list);

/*--- PRINTING THE GARBAGE LINKED LIST ---*/

void		print_garbage_collector();

#endif