#include <stdlib.h>
#include <stdio.h>
#include "builtins.c"
#include "launch.c"

int csh_execute(char **args) {
    if (args[0] == NULL) {
        return 1;
    }
    for (int i = 0; i < num_builtins(); i++) {
        if (strcmp(args[0], csh_builtins[i]) == 0) {
            return (*builtin_func[i])(args);
        }
    }

    return csh_launch(args);
}