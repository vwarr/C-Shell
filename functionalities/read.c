#include <stdio.h>
#include <stdlib.h>

#define INITIAL_BUFFER_SIZE 1024

char *csh_read_line() {
    int buf_size = INITIAL_BUFFER_SIZE;
    int pos = 0;
    char *buffer = (char*) malloc(sizeof(char) * buf_size);
    int c;

    if (!buffer) {
        fprintf(stderr, "csh: memory allocation failure\n");
        exit(EXIT_FAILURE);
    }

    while(1) {
        c = getchar();
        if (c == '\0' || c == EOF || c == '\n') {
            buffer[pos] = '\0';
            return buffer;
        } else {
            buffer[pos] = c;
        }
        pos++;
        if (pos >= buf_size) {
            buffer = realloc(buffer, sizeof(char) * (buf_size + INITIAL_BUFFER_SIZE));
            if (!buffer) {
                fprintf(stderr, "csh: memory allocation failure\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}