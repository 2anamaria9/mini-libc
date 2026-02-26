// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	int x = syscall(__NR_truncate, path, length);
	if (x < 0) {
		errno = -x;
		return -1;
	}
	return x;
}
