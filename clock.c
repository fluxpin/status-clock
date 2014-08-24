#include <unistd.h>

#include "clock.h"
#include "util.h"

struct str {
        size_t max;
        char *buf;
};

const char *NAME;

int main(int argc, char *argv[])
{
        time_t epochtime;
        struct tm *walltime;
        struct str clock = {0, NULL};

        NAME = argc ? argv[0] : __FILE__;
        if (argc != 2)
                die("Usage: %s <format>\n");

        setvbuf(stdout, NULL, _IOLBF, 0);
        while (1) {
                epochtime = time(NULL);
                walltime = localtime(&epochtime);
                ustrftime(&clock.buf, &clock.max, argv[1], walltime);
                puts(clock.buf);
                sleep(60 - walltime->tm_sec);
        }
}
