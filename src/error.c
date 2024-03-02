#include "pipex.h"

void error_pipe(int error)
{
    if  (error == 1)
      write(2, "Error creating pipe\n", 19);
    else if (error == 2)
      write(2, "permission denied\n", 19);
    else if (error == 3)
      write(2, "command not found\n", 17);
    else 
     return ;

    exit(EXIT_FAILLURE);
}