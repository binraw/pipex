/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:18:58 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/22 15:40:40 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    int fd[2];

    if (argc == 5)
    {
        pipex_process(argv, envp, fd);
    }
    return (0);
}

int pipex_process(char **argv, char ** envp, int *fd)
{
    pid_t first_child;
    pid_t second_child;
    
    first_child = fork();
    second_child = fork();
    
    if (first_child == 0)
        child_process(argv, envp, fd);

    if (second_child == 0)
        second_child_process(argv, envp, fd);

    waitpid(first_child, NULL, 0);
     return (0);
    
}

int child_process(char **argv, char **envp, int *fd)
{
    int filein;
	char	**command;
	char	*path_command;
	
	command = create_cmd(argv, 3);  
	path_command = create_path(command[0], envp);
	filein = open(argv[1], O_RDONLY);
    dup2(filein, 0);
    dup2(fd[1], 1);
    execve(path_command, command, envp);
     return (0);
}

char 	**create_cmd(char **argv, int i)
{
	char **cmd;

	cmd = ft_split(argv[i], ' ');

	return (cmd);
}

int second_child_process(char **argv, char **envp, int *fd)
{
    int fileout;
	char	*command;
	char	*path_command;

	command = create_cmd(argv, 4);
	path_command = create_path(command, envp);
    fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
    dup2(fd[1], 0);
    dup2(fileout, 1);
    execve(path_command, command, envp);
     return (0);
}

