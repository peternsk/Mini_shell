#include "minishell.h"


int is_files_valide(t_cmd *cmds)
{
    t_cmd *current;
    t_files *curr_files;

    current = cmds;
    while (current != NULL)
    {
        if (current->files)
        {
            curr_files  = current->files;
            while (curr_files != NULL)
            {
                if (curr_files->error == -1 || current->exit_here_doc != 0)
                    return (-1);
                curr_files = curr_files->next;
            }
        }
        current = current->next;
    }
    return (0);
}
