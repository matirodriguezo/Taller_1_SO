#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64

int main() {
    char input[MAX_INPUT];
    char *args[MAX_ARGS];

    while (1) {
        // 1) PROMPT
        printf("myshell> ");
        fflush(stdout);

        // 2) LEER ENTRADA
        if (fgets(input, MAX_INPUT, stdin) == NULL) break;

        // Eliminar el salto de línea
        input[strcspn(input, "\n")] = '\0';

        // 5) ENTER SIN COMANDO → volver al prompt
        if (strlen(input) == 0) continue;

        // Parsear argumentos
        int i = 0;
        args[i] = strtok(input, " ");
        while (args[i] != NULL) {
            i++;
            args[i] = strtok(NULL, " ");
        }

        // 3) COMANDO exit
        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        }

        // 6) FORK + EXEC (foreground)
        pid_t pid = fork();

        if (pid == 0) {
            // Proceso hijo: ejecutar comando
            execvp(args[0], args);

            // 4) Si execvp falla → comando no existe
            perror("Error");
            _exit(1);

        } else if (pid > 0) {
            // Proceso padre: esperar al hijo
            waitpid(pid, NULL, 0);

        } else {
            perror("fork falló");
        }
    }
    return 0;
}