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
## Prototype
* ``` char **split_args(char *command); ```
* ``` void free_args(char **args); ```
* ``` char *clear_command(char *command); ```
* ``` int is_path(char *command); ```
* ``` char *scan_dir(char *command); ```
* ``` int is_builtin(char **args, int status, char *input); ```

## Requirements
* Allowed editors: vi, vim, emacs.
* All your files will be compiled on Ubuntu 20.04 LTS using gcc.
* All your files should end with a new line.
* A README.md file, at the root of the folder of the project is mandatory.
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* Your shell should not have any memory leaks.
* No more than 5 functions per file.
* All your header files should be include guarded.

## MAN page

## Authors
- [@Elie Fétis](https://github.com/JustGodWork)
- [Cedrid](https://github.com/CedricKizLeader)
- [Ruth Fonseca](https://github.com/ruthfonsecass)
  


