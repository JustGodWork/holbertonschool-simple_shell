#ifndef DEBUG_H
#define DEBUG_H

/* debug_print.c */
int dinfo(const char *format, ...);
int derror(const char *format, ...);
int dwarn(const char *format, ...);
int dsuccess(const char *format, ...);

#endif /* DEBUG_H */
