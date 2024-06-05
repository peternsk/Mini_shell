#include "minishell.h"

t_cmd *init_curr_cmd()
{
    t_cmd *node;
    node = malloc_and_add(sizeof(t_cmd));
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
    node->exit_here_doc = 0;
    node->files = NULL;
    node->next = NULL;
    node->glob = NULL;
    return (node);
}


char   **init_cmds(char **tmp, t_minish *m_s)
{
    t_cmd       *curr;
    t_cmd       *new;
    t_cmdlts    *currList;

    curr = NULL;
    currList = NULL;
    m_s->index = 0;
    if (m_s->comd_lst)
    {
        currList = m_s->comd_lst;
        while (currList != NULL)
        {
            new = init_curr_cmd();
            new->cmd_name  = *currList->command;
            new->glob = m_s;
            new->envp = list_to_tab(&m_s->env_varlst);
            new->files = currList->redlst;
            new->type = type_cmds(new->cmd_name);
            new->av_cmd  = currList->command;
            add_cmds(&curr, new);
            currList = currList->next;
        }
        cout_cmds_pipes(curr);
        run_commands(curr);
        tmp = list_to_tab(&curr->glob->env_varlst);
		add_filename_unlnk_lst(&m_s->comd_lst, m_s);
    }
    return (tmp);
}
