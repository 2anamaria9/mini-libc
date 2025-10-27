#include <time.h>
#include <internal/syscall.h>
#include <errno.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    int x = syscall(__NR_nanosleep, req, rem);
    if (x < 0) {
        errno = -x;
        return -1;
    }
    return 0;
}
