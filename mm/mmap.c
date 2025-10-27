// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	long x = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
	if (x < 0) {
		errno = -x;
		return MAP_FAILED;
	}
	return (void *)x;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	long x = syscall(__NR_mremap, old_address, old_size, new_size, flags);
	if (x < 0) {
		errno = -x;
		return MAP_FAILED;
	}
	return (void *)x;
}

int munmap(void *addr, size_t length)
{
	long x = syscall(__NR_munmap, addr, length);
	if (x < 0) {
		errno = -x;
		return -1;
	}
	return x;
}
