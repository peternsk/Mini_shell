/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:58:48 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/04/19 20:43:48 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    node->nb_cmds = 0;
    node->nb_pipes = 0;
    node->is_vars = false;
    node->id = -1;
    node->type = -1;
    node->files = NULL;
    node->next = NULL;
    return (node);
}


void print_cmds(t_cmd *s_cmd)
{
    t_cmd *curr;
    curr = s_cmd;
    int     i = 0;
    printf("======================================is init=============================================\n");
    while (curr != NULL)
    {
        printf("cmd->type %d\n", curr->type);
        printf("curr->index %d\n", curr->index);
        printf("curr->cmd_name %s\n", curr->cmd_name);
        if (curr->files)
            printf("curr->files->name %s\n", curr->files->name);
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
// aouter le files [en cours]
// ajouter nb_cmd [done]
// ajouter nb_pipes [done]
// ajouter le type de cmds

void    init_cmds(char **env, t_minish *m_s)
{
    t_cmd   *curr;
    t_cmd   *new;
    t_cmdlts *currList;
    
    curr = NULL;
    currList = NULL;
    if (m_s->cmdLst)
    {
        currList = m_s->cmdLst;
        while (currList != NULL)
        {
            new = init_curr_cmd();
            new->cmd_name  = *m_s->cmdLst->command;
            new->av_cmd  = m_s->cmdLst->command;
            add_cmds(&curr, new, env, m_s->cmdLst->redlst);
            currList = currList->next;
        }
        cout_cmds_pipes(&curr);
        print_cmds(curr);
        
    }
}

void fake()
{
    
}