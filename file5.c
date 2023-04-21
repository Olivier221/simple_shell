#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_BUFFER 1024
#define MAX_ARGS 64

extern char **environ;

void print_env()
{
    int i = 0;
    while (environ[i])
    {
        printf("%s\n", environ[i]);
        i++;
    }
}

int main(void)
{
    char buffer[MAX_BUFFER];
    char *args[MAX_ARGS];
    int status;

    while (1)
    {
        printf("$ ");
        fgets(buffer, MAX_BUFFER, stdin);
        buffer[strlen(buffer) - 1] = '\0';

        if (strcmp(buffer, "exit") == 0) {
            printf("Goodbye!\n");
            exit(EXIT_SUCCESS);
        }

        if (strcmp(buffer, "env") == 0) {
            print_env();
            continue;
        }

        pid_t pid = fork();

        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0)
        {
            // child process
            int i = 0;
            char *token = strtok(buffer, " ");
            while (token != NULL)
            {
                args[i] = token;
                token = strtok(NULL, " ");
                i++;
            }
            args[i] = NULL;

            execvp(args[0], args);

            perror("execvp");
            exit(EXIT_FAILURE);
        }
        else
        {
            // parent process
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}
