#ifndef CLOCK_H
#define CLOCK_H

#include <stdio.h>
#include <stdlib.h>

extern const char *NAME;

#define die(fmt, ...)                              \
do {                                               \
        fprintf(stderr, fmt, NAME, ##__VA_ARGS__); \
        exit(1);                                   \
} while (0)

#endif /* CLOCK_H */
