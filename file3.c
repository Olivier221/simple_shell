#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_PATH_LENGTH 1024
#define MAX_ARGS 64

char *get_path(void)
{
    char *path = getenv("PATH");
    if (path == NULL) {
        return NULL;
    }

    char *path_copy = strdup(path);
    if (path_copy == NULL) {
        return NULL;
    }

    return path_copy;
}

char **parse_args(char *input)
{
    char **args = malloc(sizeof(char*) * MAX_ARGS);
    if (args == NULL) {
        return NULL;
    }

    char *arg = strtok(input, " \t\n");
    int i = 0;
    while (arg != NULL && i < MAX_ARGS - 1) {
        args[i] = arg;
        arg = strtok(NULL, " \t\n");
        i++;
    }
    args[i] = NULL;

    return args;
}

void execute_command(char **args, char *path)
{
    if (access(args[0], X_OK) == 0) {
        execve(args[0], args, NULL);
    } else {
        char *dir = strtok(path, ":");
        while (dir != NULL) {
            char *full_path = malloc(MAX_PATH_LENGTH);
            if (full_path == NULL) {
                perror("malloc");
                exit(EXIT_FAILURE);
            }
            snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", dir, args[0]);
            if (access(full_path, X_OK) == 0) {
                execve(full_path, args, NULL);
            }
            free(full_path);
            dir = strtok(NULL, ":");
        }
    }
}

int main(void)
{
    char *path = get_path();
    if (path == NULL) {
        fprintf(stderr, "Error: PATH environment variable not found\n");
        exit(EXIT_FAILURE);
    }

    char input[1024];
    while (1) {
        printf(":) ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        char **args = parse_args(input);
        if (args == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            execute_command(args, path);
            fprintf(stderr, "Error: command not found\n");
            exit(EXIT_FAILURE);
        } else {
            wait(NULL);
            free(args);
        }
    }

    free(path);
    return 0;
}
