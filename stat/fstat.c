// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	int x = syscall(__NR_fstat, fd, st);
	if (x < 0) {
		errno = -x;
		return -1;
	}
	return x;
}
