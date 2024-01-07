#include "shell_progress.h"

/**
 * main - Fonction principale du shell
 *
 * Return: 0 en cas de succès
 */


int main(void)

{
	char cmd[256];

	while (1)
	{
		printf("> ");
		if (fgets(cmd, sizeof(cmd), stdin) == NULL)
		{
			printf("\n");
			break;
		}
		cmd[strcspn(cmd, "\n")] = 0;

		if (system(cmd) == -1)
		{
			printf("./shell: No such file or directory\n");
		}
	}
	return (0);
}
