

#include "minishell.h"

int is_there_here_doc(t_cmd *current)
{
   t_files *files;
   int     i;

   i = 0;
   files = current->files;
   while (files != NULL)
   {
      if (files->type == here_doc)
         i++;
      files = files->next;
   }
   return (i);
}
