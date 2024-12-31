#include <stdio.h>
#include "functionalities/read.c"
#include "functionalities/split.c"
#include "functionalities/execute.c"

void csh_loop() {
    char *line;
    char **args;
    int status; 
    do {
        printf("csh >");
        line = csh_read_line();
        args = csh_split_line(line);
        status = csh_execute(args);

        free(line);
        free(args);
    } while (status);
}