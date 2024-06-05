

#include "minishell.h"

void    count_types_files(t_cmd *current)
{
    t_files   *now_files;
    int     i;

    i = 0;
    now_files = current->files;
    while (now_files != NULL)
    {
        now_files->index_out = i;
        i++;
        now_files = now_files->next;
    }
}

t_files    *g_last_file_type(t_files *files, int type, int last)
{
    t_files *tmp;
    t_files *last_files;

    last_files = NULL;
    if (files)
    {
        tmp = files;
        while (tmp != NULL)
        {
            if (tmp->type == type && tmp->put_last == last)
                last_files = tmp;
            tmp = tmp->next;
        }
    }
    // if (last_files)
        // printf("we are here -> last file %s  index %d \n", last_files->name_here_doc, last_files->index_out);
    return (last_files);
}

t_files  *is_there_here_doc(t_cmd *current)
{
   t_files *here_doc_files;
   t_files *IPR_file;

   here_doc_files = g_last_file_type(current->files, here_doc, 1);
   IPR_file = g_last_file_type(current->files, IPR, 1);
   count_types_files(current);
   count_types_files(current);
   if (IPR_file && here_doc_files)
   {
        if (here_doc_files->index > IPR_file->index)
            return (here_doc_files);
        return (IPR_file);
   }
   if (IPR_file)
        return (IPR_file);
   return (here_doc_files);
}