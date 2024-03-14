/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:39:33 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/03/12 13:04:31 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    **get_env(char **envp)
{
    char	**paths;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4) && envp[i])
		i++;
	paths = ft_split(envp[i] + 5, ':');
    if (!paths)
    {
        ft_free_tab(envp);
        return (NULL);
    }
	return (paths);
}

char *create_path(char *cmd, char **envp)
{
    int     i;
    char    **paths;
    char    *path_cmd;
    char    *join_path_cmd;

    i = 0;
      if (access(cmd, F_OK) == 0)
            return (cmd);
    paths = get_env(envp);
    if (!paths)
        return (NULL);
    while (paths[i])
    {
        join_path_cmd = ft_strjoin(paths[i], "/");
        path_cmd = ft_strjoin(join_path_cmd, cmd);
        free(join_path_cmd);
        if (access(path_cmd, X_OK) == 0)
        {
            ft_free_tab(paths);
            return (path_cmd);
        }
        else
        {
            free(path_cmd);
            i++ ;
        }
    }
    ft_free_tab(paths);
    free(cmd);
    return (NULL);
}


void    ft_free_tab(char  **tab)
{
    size_t i;
    i = 0;

    while(tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

