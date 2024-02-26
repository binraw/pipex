/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:34:28 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/22 15:39:31 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h> 
# include <sys/types.h>
# include <sys/wait.h>
# include "../lib/libft/libft.h"



int pipex_process(char **argv, char ** envp, int *fd);
int child_process(char **argv, char **envp, int *fd);
int second_child_process(char **argv, char **envp, int *fd);
char 	**create_cmd(char **argv, int i);
char    **get_env(char **envp);
int main(int argc, char **argv, char **envp);
char *create_path(char *cmd, char **envp);

#endif