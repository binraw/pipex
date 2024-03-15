/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:39:42 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/03/15 15:29:27 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_pipe(int error)
{
	if (error == 1)
		write(2, "Error creating pipe\n", 20);
	else if (error == 2)
		write(2, "permission denied\n", 19);
	else if (error == 3)
		write(2, "command not found\n", 18);
	else 
		return ;
}
void	error_file(char **command, char *path_command)
{
	if (command)
		ft_free_tab(command);
	free(path_command);
	error_pipe(2);
	exit(1);
}

void	error_path(char **command)
{
	if (command)
		free(command);
	error_pipe(3);
	exit(127);
}
