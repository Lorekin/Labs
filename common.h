#ifndef HLDETECTOR_COMMON_H
#define HLDETECTOR_COMMON_H

/*
 * When greater than zero, makes internals print.
 */
extern int hl_debug;

/*
 * Callback to be used by proceed_hyperlinks(), see below.
 */
typedef void (*hlhandler)(const char *uri);

/*
 * Prints to stdout all http(s) hyperlinks found in 'f', one per line.
 *
 * Returns non-zero if I/O error was detected upon reading from 'f',
 * zero otherwise (even if no hyperlinks were found).
 */
int	proceed_hyperlinks(FILE *f, const char *path, hlhandler handler);

#endif
