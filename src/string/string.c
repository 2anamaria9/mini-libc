// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	while (*source != '\0') {
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	size_t i;
	for (i = 0; i < len && *source != '\0'; i++) {
		destination[i] = source[i];
	}
	for (; i < len; i++)
		destination[i] = '\0';
	return destination;
}

char *strcat(char *destination, const char *source)
{
	while (*destination != '\0')
		destination++;
	while (*source != '\0') {
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	size_t i;
	while (*destination != '\0')
		destination++;
	for (i = 0; i < len; i++) {
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0') {
		if (*str1 > *str2)
			return 1;
		else if (*str1 < *str2)
				return -1;
		str1++;
		str2++;
	}
	if (*str1 > *str2)
			return 1;
		else if (*str1 < *str2)
				return -1;
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	size_t i;
	for (i = 0; i < len && *str1 != '\0' && *str2 != '\0'; i++) {
		if (*str1 > *str2)
			return 1;
		else if (*str1 < *str2)
				return -1;
		str1++;
		str2++;
	}
	if (i < len && *str1 > *str2)
		return 1;
	else if (i < len && *str1 < *str2)
			return -1;
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	while (*str != '\0') {
		if (*str == c)
			return (char *)str;
		str++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	const char *p = NULL;
	while (*str != '\0') {
		if (*str == c)
			p = str;
		str++;
	}
	return (char *)p;
}

char *strstr(const char *haystack, const char *needle)
{
	while (*haystack != '\0') {
		const char *x = haystack;
		const char *y = needle;
		while (*x != '\0' && *y != '\0' && *x == *y) {
			x++;
			y++;
		}
		if (*y == '\0')
			return (char *)haystack;
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	const char *p = NULL;
	while (*haystack != '\0') {
		const char *x = haystack;
		const char *y = needle;
		while (*x != '\0' && *y != '\0' && *x == *y) {
			x++;
			y++;
		}
		if (*y == '\0')
			p = haystack;
		haystack++;
	}
	return (char *)p;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *dest = destination;
	const char *src = source;
	size_t i;
	for (i = 0; i < num; i++) {
		*dest = *src;
		dest++;
		src++;
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *dest = destination;
	const char *src = source;
	if (dest < src) {
		size_t x = 0;
		while (x < num) {
			*dest = *src;
			dest++;
			src++;
			x++;
		}
	} else {
		size_t x = num;
		dest += num - 1;
		src += num - 1;
		while (x > 0) {
			*dest = *src;
			dest--;
			src--;
			x--;
		}
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const char *p1 = ptr1;
	const char *p2 = ptr2;
	size_t x = 0;
	while (x < num && *p1 != '\0' && *p2 != '\0') {
		if (*p1 > *p2)
			return 1;
		else if (*p1 < *p2)
				return -1;
		x++;
		p1++;
		p2++;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	char *src = source;
	char val = value;
	size_t x = 0;
	while (x < num) {
		*src = val;
		src++;
		x++;
	}
	return source;
}
