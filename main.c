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
    
}

int child_process(char **argv, char **envp, int *fd)
{
    int filein;
	char	*command;
    // char **cmd est le resultat du split de argv
	command = create_cmd(argv, 2);
    // char *path a definir avec la fonction qui cherche le chemin
    filein = open(argv[1], O_RDONLY);
    dup2(filein, 0);
    dup2(fd[1], 1);

    execve(path, cmd, envp);
    
    
}

char 	*create_cmd(char **argv, int i)
{
	char *cmd;

	cmd = ft_split(argv[i], ' ');

	return (cmd);
}

int second_child_process(char **argv, char **envp, int *fd)
{
    int fileout;

    fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
    dup2(fd[1], 0);
    dup2(fileout, 1);
    
    execve(path, cmd, envp);
}

