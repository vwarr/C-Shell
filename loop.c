#include <stdio.h>
#include <read.c>
#include <split.c>

void csh_loop() {
    char *line;
    char **args;
    int status; 
    do {
        printf(">");
        line = csh_read_line();
        args = csh_split_line(line);
        status = csh_execute(args);

        free(line);
        free(args);
    } while (status);
}