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

void expansion_change_directory(t_cmd *cmd, char **pwd_change)
{
    if (chdir(cmd->av_cmd[1]) == 0)
    {
        pwd_change[2] = ft_strjoin("PWD=", get_live_path());
        is_add_envp(cmd->glob->envVarlst, pwd_change);
    }
    else 
    {
        write(2, "minishell: ", ft_strlen("minishell: "));
        perror(cmd->av_cmd[1]);
    }
    // free le bhy
}
void    ft_cd(t_cmd *cmds)
{
    char   **pwd_change;

    pwd_change = (char **)malloc(sizeof(char *) * 4);
    pwd_change[0] = ft_strdup("cd\0");
    pwd_change[3] =  NULL;
    pwd_change[1] = ft_strjoin("OLDPWD=", get_live_path());
    if (!cmds->av_cmd[1])
    {
        chdir(from_envp_get_home(cmds->envp));
        pwd_change[2] =  ft_strjoin("PWD=", get_live_path());
        is_add_envp(cmds->glob->envVarlst, pwd_change);
        // free le bhy
    }
    else 
        expansion_change_directory(cmds, pwd_change);
}
 