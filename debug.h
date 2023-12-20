#ifndef DEBUG_H
#define DEBUG_H

#define DINFO "[Info]"
#define DERROR "[Error]"
#define DWARN "[Warn]"
#define DSUCCESS "[Success]"

/* print_debug.c */
int print_debug(char *type, const char *format, ...);
int dinfo(const char *format, ...);
int derror(const char *format, ...);
int dwarn(const char *format, ...);
int dsuccess(const char *format, ...);

void dfree(char *ptr);

#endif /* DEBUG_H */
