// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	int x = syscall(__NR_close, fd);
	if (x < 0) {
		errno = -x;
		return -1;
	}
	return x;
}
