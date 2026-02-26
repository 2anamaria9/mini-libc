#include <unistd.h>
#include <stdio.h>

int puts(const char *s)
{
    size_t n = 0;
    while (s[n] != '\0')
        n++;
    size_t x = write(1, s, n);
    if (x != n)
        return -1;
    x = write(1, "\n", 1);
    if (x != 1)
        return -1;
    return 0;
}
