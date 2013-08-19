#ifndef UTIL_H
#define UTIL_H

#include <stddef.h>
#include <time.h>

size_t ustrftime(char **s, size_t *max, const char *format,
                 const struct tm *tm);

#endif /* UTIL_H */
