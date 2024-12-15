#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int csh_launch(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1){
            perror("csh");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("csh");
    } else {
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}