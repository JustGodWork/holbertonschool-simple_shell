#include "simple_shell.h"

/**
 * main - Entry point
 * Return (0) always success
*/
int main(void) {
	/* char *program_name = argv[0]; */
	char *command = malloc(1024 * sizeof(char));
	size_t command_len = 1024;
	int user_input = 0;

	while (user_input != EOF) {
		printf("$ ");

		user_input = getline(&command, &command_len, stdin);

		/*Supprimer le caractère de nouvelle ligne à la fin de la commande*/
        command[strcspn(command, "\n")] = '\0';
		execute_command(&command);

		if (user_input == EOF)
			putchar('\n');
	};

	return (0);
}
