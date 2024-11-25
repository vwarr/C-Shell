#include <stdio.h>
#include <read.c>

void csh_loop() {
    char *line;
    char **args;
    int status; 
    do {
        printf(">");
        line = csh_read_line();
    } while (status);
}