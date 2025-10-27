// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	int x = syscall(__NR_open, filename, flags);
	if (x < 0) {
		errno = -x;
		return -1;
	}
	return x;
}
