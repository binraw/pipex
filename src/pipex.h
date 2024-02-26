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
# include "lib/libft.h"



int pipex_process(char **argv, char **envp, int fd);
char    **get_env(char **env);
char *create_path(char *cmd, char **env);

#endif