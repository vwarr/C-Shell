#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int csh_cd(char **args);
int csh_help(char **args);
int csh_exit(char **args);
int csh_echo(char **args);

char *csh_builtins[] = {
    "cd",
    "help",
    "exit",
    "echo"
};

int (*builtin_func[]) (char **) = {
  &csh_cd,
  &csh_help,
  &csh_exit,
  &csh_echo
};

int num_builtins() {
    return sizeof(csh_builtins) / sizeof(char *);
}
    

int csh_cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "csh: expected argument to \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("csh");
        }
    }
    return 1;
}

int csh_help(char **args) {
    printf("C-SHell:\n - Type program names and arguments, then press enter. \n\n Builtins: \n");
    for (int i = 0; i < num_builtins(); i++) {
    printf("  %s\n", csh_builtins[i]);
    }
    return 1;
}

int csh_exit(char **args) {
    return 0;
}

int csh_echo(char **args) {
    for (int i = 1; args[i] != NULL; i++) {
        printf("%s ", args[i]);
    }
    printf("\n");
    return 1;
}