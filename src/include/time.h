#include <internal/types.h>
#include <errno.h>

struct timespec {
    size_t tv_sec;
    long tv_nsec;
};

unsigned int sleep(unsigned int seconds);
int nanosleep(const struct timespec *req, struct timespec *rem);
