// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/types.h>
#include <unistd.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

#define makedev(x, y) ( \
		(((x)&0xfffff000ULL) << 32) | \
	(((x)&0x00000fffULL) << 8) | \
		(((y)&0xffffff00ULL) << 12) | \
	(((y)&0x000000ffULL)) \
	)

/* Structure describing file characteristics as defined in linux/stat.h */
struct statx {
	uint32_t stx_mask;
	uint32_t stx_blksize;
	uint64_t stx_attributes;
	uint32_t stx_nlink;
	uint32_t stx_uid;
	uint32_t stx_gid;
	uint16_t stx_mode;
	uint16_t pad1;
	uint64_t stx_ino;
	uint64_t stx_size;
	uint64_t stx_blocks;
	uint64_t stx_attributes_mask;
	struct {
		int64_t tv_sec;
		uint32_t tv_nsec;
		int32_t pad;
	} stx_atime, stx_btime, stx_ctime, stx_mtime;
	uint32_t stx_rdev_major;
	uint32_t stx_rdev_minor;
	uint32_t stx_dev_major;
	uint32_t stx_dev_minor;
	uint64_t spare[14];
};

int fstatat_statx(int fd, const char *restrict path, struct stat *restrict st, int flag)
{
	struct statx s;
	int x = syscall(__NR_statx, fd, path, flag, 0, &s);
	if (x != 0)
		return -1;
	struct stat aux = {0};
	*st = aux;
	st->st_blksize = s.stx_blksize;
	st->st_blocks = s.stx_blocks;
	st->st_gid = s.stx_gid;
	st->st_ino = s.stx_ino;
	st->st_mode = s.stx_mode;
	st->st_nlink = s.stx_nlink;
	st->st_size = s.stx_size;
	st->st_uid = s.stx_uid;
	st->st_atime = s.stx_atime.tv_sec;
	st->st_atime_nsec = s.stx_atime.tv_nsec;
	st->st_ctime = s.stx_ctime.tv_sec;
	st->st_ctime_nsec = s.stx_ctime.tv_nsec;
	st->st_mtime = s.stx_mtime.tv_sec;
	st->st_mtime_nsec = s.stx_mtime.tv_nsec;
	st->st_dev = makedev(s.stx_dev_major, s.stx_dev_minor);
	st->st_rdev = makedev(s.stx_rdev_major, s.stx_rdev_minor);
	return 0;
}

int fstatat(int fd, const char *restrict path, struct stat *restrict st, int flag)
{
	return fstatat_statx(fd, path, st, flag);
}
