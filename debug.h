#ifndef DEBUG_H
#define DEBUG_H

#define DEBUG_INFO "Info"
#define DEBUG_ERROR "Error"
#define DEBUG_WARN "Warn"
#define DEBUG_SUCCESS "Success"
#define info(message) print_debug(DEBUG_INFO, message)
#define error(message) print_debug(DEBUG_ERROR, message)
#define warn(message) print_debug(DEBUG_WARN, message)
#define success(message) print_debug(DEBUG_SUCCESS, message)

/* debug.c */
int print_debug(const char *type, const char *format, ...);
void debug_free(char *buffer, const char *message);

#endif /* DEBUG_H */
