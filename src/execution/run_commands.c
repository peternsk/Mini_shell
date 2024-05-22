#include "minishell.h"

// void print_cmds(t_cmd *s_cmd)
// {
//     t_cmd *curr;
//     t_files *curr_f;
    
//     curr_f = NULL;
//     curr = s_cmd;
//     int     i = 0;
//     printf("======================================is init=============================================\n");
//     while (curr != NULL)
//     {
//         printf("cmd->type %d\n", curr->type);
//         printf("curr->index %d\n", curr->index);
//         printf("curr->cmd_name %s\n", curr->cmd_name);
//         if (curr->files)
//         {
//             curr_f = curr->files;
//             while (curr_f != NULL)
//             {
//                 printf("curr->files->name %s and files type %d \n", curr_f->name, curr_f->type);
//                 curr_f = curr_f->next;
//             }
            
//         }
//         printf("cur->nb_pipes %d\n", curr->nb_pipes);
//         printf("cur->nb_cmds %d\n", curr->nb_cmds);
//         printf("======== av ============\n");
//         i  = 0;
//         if (curr->av_cmd)
//         {
//             while (curr->av_cmd[i] != NULL)
//             {
//                 printf("curr->av[%d] %s \n",  i, curr->av_cmd[i]);
//                 i++;
//             }
//         }
//         printf("======== end ============\n");
//         curr = curr->next;
//     }
//     printf("======================================ends init=============================================\n");
// }

int   run_commands(t_cmd *cmds)
{
    char    *envp_path;

    if (!cmds)
        return (-1);
    envp_path = get_envp_path(cmds->envp);
    if (cmds->nb_cmds == 1 && cmds->nb_pipes == 0)
    {
        if (single_command(cmds, cmds->envp, envp_path) == -1)
            return (-1);
    }
    else
        commands(cmds, envp_path);
    return (1);
}