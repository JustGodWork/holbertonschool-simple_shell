#ifndef PROCESS_H
#define PROCESS_H

void create_process(
	char *command,
	char **envp,
	char *program_name,
	int *status
);

#endif /* PROCESS_H */
