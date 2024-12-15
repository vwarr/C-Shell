#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CSH_TOK_BUFSIZE 64
#define CSH_TOK_DELIM " \t\r\n\a"

char **csh_split_line(char* line) {
    int bufsize = CSH_TOK_BUFSIZE;
    int pos = 0;
    char **tokens = malloc(CSH_TOK_BUFSIZE * sizeof(char*));
    char *token;
    if (!tokens) {
        fprintf(stderr, "csh: allocation error\n");
        exit(EXIT_FAILURE);
    }
    token = strtok(line, CSH_TOK_DELIM);
    while (token != NULL) {
        tokens[pos] = token;
        pos++;

        if (pos >= bufsize) {
            bufsize += CSH_TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "csh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, CSH_TOK_DELIM);
    }
    tokens[pos] = NULL;
    return tokens;
}