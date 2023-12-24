# simple_shell
To develop a customized shell that enhances user interaction with the operating system, offering advanced features and an intuitive interface.

## Mandatory Tasks
* Write a README / Write a man for your shell
* Write a beautiful code that passes the Betty checks
* Write a UNIX command line interpreter.
* Handle command lines with arguments
* Handle the PATH
* Implement the exit built-in, that exits the shell
* Implement the env built-in, that prints the current environment
*
## Prototypes
* ``` char **split_args(char *command); ``` Split full command in separated arguments
* ``` void free_args(char **args); ``` Unallocate memory for arguments
* ``` char *clear_command(char *command); ``` Remove unwanted spaces from the command
* ``` int is_path(char *command); ``` Check if command contains a path or not
* ``` char *scan_dir(char *command); ``` Search path for entered command
* ``` int is_builtin(char **args, int status, char *input); ``` Check if command is one of our custom command

## Requirements
* Allowed editors: vi, vim, emacs.
* All your files will be compiled on Ubuntu 20.04 LTS using gcc.
* All your files should end with a new line.
* A README.md file, at the root of the folder of the project is mandatory.
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* Your shell should not have any memory leaks.
* No more than 5 functions per file.
* All your header files should be include guarded.

## Compilation
* In order to compile you need **GCC (Linux)** or **MinGW (Windows)**
* Command: ```gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh```
* If you want to compile and execute at the same time use this command: ```gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh &&./hsh```

## Examples
* Example #1: ```echo "/bin/ls -l" | ./hsh```
**Output (Example #1):**
```
total 76
-rwxrwxrwx 1 justgod justgod 17184 Dec 15 01:03 a.out
-rwxrwxrwx 1 justgod justgod  1564 Dec 21 10:40 arguments.c
-rwxrwxrwx 1 justgod justgod   217 Dec 18 09:30 AUTHORS
-rwxrwxrwx 1 justgod justgod  1054 Dec 22 23:26 buitin.c
-rwxrwxrwx 1 justgod justgod   955 Dec 22 21:25 command.c
-rwxrwxrwx 1 justgod justgod   223 Dec 21 10:40 debug.h
-rwxrwxrwx 1 justgod justgod  1538 Dec 21 10:40 debug_print.c
-rwxrwxrwx 1 justgod justgod 17880 Dec 22 23:27 hsh
-rwxrwxrwx 1 justgod justgod  2788 Dec 22 23:49 index.c
-rwxrwxrwx 1 justgod justgod   244 Dec 21 10:40 libraries.h
-rwxrwxrwx 1 justgod justgod   841 Dec 23 17:01 man_page
-rwxrwxrwx 1 justgod justgod  1794 Dec 22 23:38 path.c
-rwxrwxrwx 1 justgod justgod  1466 Dec 24 13:40 README.md
-rwxrwxrwx 1 justgod justgod   807 Dec 22 21:25 simple_shell.h
```
* Example #2: ```echo "ls -la" | ./hsh```
**Output (Example #2):**
```
total 76
drwxrwxrwx 1 justgod justgod   512 Dec 24 13:40 .
drwxrwxrwx 1 justgod justgod   512 Dec 22 22:35 ..
-rwxrwxrwx 1 justgod justgod 17184 Dec 15 01:03 a.out
-rwxrwxrwx 1 justgod justgod  1564 Dec 21 10:40 arguments.c
-rwxrwxrwx 1 justgod justgod   217 Dec 18 09:30 AUTHORS
-rwxrwxrwx 1 justgod justgod  1054 Dec 22 23:26 buitin.c
-rwxrwxrwx 1 justgod justgod   955 Dec 22 21:25 command.c
-rwxrwxrwx 1 justgod justgod   223 Dec 21 10:40 debug.h
-rwxrwxrwx 1 justgod justgod  1538 Dec 21 10:40 debug_print.c
drwxrwxrwx 1 justgod justgod   512 Dec 24 13:40 .git
-rwxrwxrwx 1 justgod justgod    32 Dec 18 09:30 .gitattributes
-rwxrwxrwx 1 justgod justgod    19 Dec 14 09:25 .gitignore
-rwxrwxrwx 1 justgod justgod 17880 Dec 22 23:27 hsh
-rwxrwxrwx 1 justgod justgod  2788 Dec 22 23:49 index.c
-rwxrwxrwx 1 justgod justgod   244 Dec 21 10:40 libraries.h
-rwxrwxrwx 1 justgod justgod   841 Dec 23 17:01 man_page
-rwxrwxrwx 1 justgod justgod  1794 Dec 22 23:38 path.c
-rwxrwxrwx 1 justgod justgod  1466 Dec 24 13:40 README.md
-rwxrwxrwx 1 justgod justgod   807 Dec 22 21:25 simple_shell.h
```

## MAN page
Located at the root of the project. See [Man Page](./man_page)

## Authors
- [@Elie Fétis](https://github.com/JustGodWork)
- [@Cedrid Chauderon](https://github.com/CedricKizLeader)
- [@Ruth Fonseca](https://github.com/ruthfonsecass)



