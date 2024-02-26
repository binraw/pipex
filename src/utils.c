#include "pipex.h"

char    **get_env(char **envp)
{
    char	**paths;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

char *create_path(char *cmd, char **envp)
{
    int     i;
    char    **paths;
    char    *path_cmd;
    char    *join_path_cmd;

    i = 0;
    paths = get_env(envp);
    while (paths[i])
    {
        join_path_cmd = ft_strjoin(paths[i], '/');
        path_cmd = ft_strjoin(join_path_cmd, cmd);
        free(join_path_cmd);
        if (access(path_cmd, X_OK) == 0)
        {
            free(paths);
            return (path_cmd);
        }
        else
        {
            free(path_cmd);
            i++ ;
        }
    }
    free(paths);
    return (NULL);

}


