#include "minishell.h"

t_cmd *init_curr_cmd()
{
    t_cmd *node;
    node = malloc(sizeof(t_cmd));
    if (!node)
        return (NULL);
    node->av_cmd = NULL;
    node->cmd_name = NULL;
    node->envp = NULL;
    node->is_file_on = 0;
    node->nb_cmds = 0;
    node->nb_pipes = 0;
    node->is_vars = false;
    node->id = -1;
    node->type = -1;
    node->files = NULL;
    node->next = NULL;
    node->glob = NULL;
    return (node);
}

void print_cmds(t_cmd **s_cmd)
{
    t_cmd *curr;
    t_files *curr_f;
    
    curr_f = NULL;
    curr = *s_cmd;
    int     i = 0;
    printf("======================================is init=============================================\n");
    while (curr != NULL)
    {
        printf("cmd->type %d\n", curr->type);
        printf("curr->index %d\n", curr->index);
        printf("curr->cmd_name %s\n", curr->cmd_name);
        if (curr->files)
        {
            curr_f = curr->files;
            while (curr_f != NULL)
            {
                printf("curr->files->name %s and files type %d \n", curr_f->name, curr_f->type);
                curr_f = curr_f->next;
            }
            
        }
        printf("cur->nb_pipes %d\n", curr->nb_pipes);
        printf("cur->nb_cmds %d\n", curr->nb_cmds);
        printf("======== av ============\n");
        i  = 0;
        if (curr->av_cmd)
        {
            while (curr->av_cmd[i] != NULL)
            {
                printf("curr->av[%d] %s \n",  i, curr->av_cmd[i]);
                i++;
            }
        }
        printf("======== end ============\n");
        curr = curr->next;
    }
    printf("======================================ends init=============================================\n");
}

// check si le file est a null
// 
char   **init_cmds(char **tmp, t_minish *m_s)
{
    t_cmd       *curr;
    t_cmd       *new;
    t_cmdlts    *currList;

    curr = NULL;
    currList = NULL;
    if (m_s->cmdLst)
    {
        currList = m_s->cmdLst;
        while (currList != NULL)
        {
            new = init_curr_cmd();
            new->cmd_name  = *currList->command;
            new->glob = m_s;
            new->envp = list_to_tab(&m_s->envVarlst);
            new->files = currList->redlst;
            new->type = type_cmds(new->cmd_name);
            new->av_cmd  = currList->command;
            add_cmds(&curr, new);
            currList = currList->next;
        }
        cout_cmds_pipes(curr);
        run_commands(curr);
        tmp = list_to_tab(&curr->glob->envVarlst);
    }
    return (tmp);
}