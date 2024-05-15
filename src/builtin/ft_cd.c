#include "minishell.h"

char    *get_home_path(char *envp)
{
    int i;

    i = 0;
    while (envp[i] != '=')
         i++;
    i++;
    return (envp + i);
}

char    *from_envp_get_home(char **envp)
{
    int i;

    i = 0;
    while (envp[i])
    {
        if (ft_strncmp(envp[i], "HOME=", ft_strlen("HOME=")) == 0)
            return (get_home_path(envp[i]));
        i++;
    }
    return (NULL);
}

char    *get_live_path()
{
    char    str[PATH_MAX];
    return (getcwd(str, PATH_MAX));
}
void    expansion_change_directory(t_cmd *cmds, char **oldPwd, char **newPwd)
{
   
    if (cmds->av_cmd[1] != NULL)
    {  
       oldPwd[0] =  ft_strjoin("OLDPWD=", get_live_path());
        if (chdir(cmds->av_cmd[1]) == 0)
        {
            newPwd[0] = ft_strjoin("PWD=", get_live_path());
            printf("new = %s ---- --- \n", newPwd[0]);
            printf("old = %s ---- --- \n", oldPwd[0]);
            ft_export(cmds, cmds->envp, newPwd, false);
            ft_export(cmds, cmds->envp, oldPwd, false);
            // for (int i = 0; cmds->envp[i] != NULL; i++)
            //     printf("%s\n", cmds->envp[i]);
        }
        else
            perror("minishell");
    }
}
// TODO: maybe change the function for better error handling
// test si le update du env function 
void    ft_cd(t_cmd *cmds)
{
    char **oldPwd;
    char **newPwd;

    oldPwd = NULL;
    newPwd = malloc(sizeof(char *) * 2);
    oldPwd = malloc(sizeof(char *) * 2);
    if (!newPwd || !oldPwd)
        return;
    newPwd[1] = NULL;
    oldPwd[1] = NULL;
    if (ft_strncmp(cmds->cmd_name, "cd", 2) == 0)
    {
        if (!cmds->av_cmd[1])
        {
            oldPwd[0] =  ft_strjoin("OLDPWD=", get_live_path());
            chdir(from_envp_get_home(cmds->envp));
            newPwd[0] =  ft_strjoin("PWD=", get_live_path());
            ft_export(cmds, cmds->envp, oldPwd, false);
            ft_export(cmds, cmds->envp, newPwd, false);

        }
        else 
            expansion_change_directory(cmds, oldPwd, newPwd);
    }
}
