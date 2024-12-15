#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char *builtins[] = {
    "cd",
    "help",
    "exit"
};

int (*builtin_func[]) (char **) = {
  &csh_cd,
  &csh_help,
  &csh_exit
};

int num_builtins() {
    return sizeof(builtins) / sizeof(char *);
}
    

int csh_cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "csh: expected argument to \"cd\"\n");
    } else {
        if (chdir(args[1] != 0)) {
            perror("csh");
        }
    }
    return 1;
}

int csh_help(char **args) {
    printf("C-SHell:\n - Type program names and arguments, then press enter. \n\n Builtins: \n");
    for (int i = 0; i < csh_num_builtins(); i++) {
    printf("  %s\n", builtins[i]);
    }
}
int csh_exit(char **args) {
    return 0;
}