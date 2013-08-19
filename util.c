#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "clock.h"
#include "util.h"

static void *umalloc(size_t size)
{
        void *ptr = malloc(size);
        if (!ptr) {
                fprintf(stderr, "%s: malloc failed\n", NAME);
                exit(1);
        }
        return ptr;
}

/* On my system calling strftime() with a null pointer returns the number
 * of characters that *would* have been written into a buffer of the given
 * size. This seems to be a GNU extension that isn't documented as such.
 */
size_t ustrftime(char **s, size_t *max, const char *format,
                 const struct tm *tm)
{
        size_t len = strftime(NULL, SIZE_MAX, format, tm);
        if (!*s || *max < len + 1) {
                free(*s);
                *s = umalloc(len + 1);
                *max = len + 1;
        }
        return strftime(*s, *max, format, tm);
}
