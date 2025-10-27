// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	int x = syscall(__NR_stat, path, buf);
	if (x < 0) {
		errno = -x;
		return -1;
	}
	return x;
}
