// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	void *addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (addr != MAP_FAILED) {
		mem_list_add(addr, size);
		return addr;
	}
	return NULL;
}

void *calloc(size_t nmemb, size_t size)
{
	void *addr = malloc(nmemb * size);
	memset(addr, 0, nmemb * size);
	return addr;
}

void free(void *ptr)
{
	if (!ptr)
		return;
	struct mem_list *item = mem_list_find(ptr);
	if (item == NULL)
		return;
	munmap(item->start, item->len);
	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	void *new = malloc(size);
	memcpy(new, ptr, size);
	return new;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	void *new = malloc(nmemb * size);
	memcpy(new, ptr, nmemb * size);
	return new;
}
