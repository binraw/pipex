/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:18:58 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/27 10:07:58 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    int fd[2];

    if (argc == 5)
    {
        pipe(fd);
        pipex_process(argv, envp, fd);
    }
    return (0);
}

int pipex_process(char **argv, char ** envp, int *fd)
{
    pid_t   first_child;
    pid_t   second_child;
    int     status;

    status = 0;
    first_child = fork();
    if (first_child == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
    if (first_child == 0)
        child_process(argv, envp, fd);
    second_child = fork();
    if (second_child == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
    if (second_child == 0)
        second_child_process(argv, envp, fd);
    close(fd[0]); 
    close(fd[1]);
    waitpid(first_child, &status, 0);
    waitpid(second_child, &status, 0);
     return (0);
    
}

int child_process(char **argv, char **envp, int *fd)
{
    int filein;
	char	**command;
	char	*path_command;
	
    
	command = create_cmd(argv, 2);
	path_command = create_path(command[0], envp);
    if (!path_command)
    {
        free(command);
        error_pipe(3);
    }
     
	filein = open(argv[1], O_RDONLY);
    if (filein == -1)
      {
        free(command);
        error_pipe(2);
    }
    dup2(filein, STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(filein);
    close(fd[1]);
    close(fd[0]);
    execve(path_command, command, envp);
    return (0);
}

char 	**create_cmd(char **argv, int i)
{
	char **cmd;

	cmd = ft_split(argv[i], ' ');
    if  (!cmd)
        ft_free_tab(cmd);
	return (cmd);
}

int second_child_process(char **argv, char **envp, int *fd)
{
    int     fileout;
	char	**command;
	char	*path_command;

    
	command = create_cmd(argv, 3);
	path_command = create_path(command[0], envp);
       if (!path_command)
       {
        free(command);
        error_pipe(3);
       }
    error_pipe(3);
    fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fileout == -1)
    {
        free(command);
        error_pipe(1);
    }   
    if (fileout == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    dup2(fd[0], STDIN_FILENO);
    dup2(fileout, STDOUT_FILENO);
    close(fileout);
    close(fd[0]);
    close(fd[1]);
    execve(path_command, command, envp);
    return (0);
}

