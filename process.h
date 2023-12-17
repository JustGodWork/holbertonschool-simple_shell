#ifndef PROCESS_H
#define PROCESS_H

#define STATE_SUCCESS 0
#define STATE_FAILURE 1

void create_process(
	char *command,
	char **envp,
	char *program_name,
	int *status
);

#endif /* PROCESS_H */
