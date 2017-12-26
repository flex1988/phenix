#ifndef __STDLIB_H__
#define __STDLIB_H__

#include <types.h>

void *malloc(size_t size);
void free(void *p);
int execvp(const char *file, char **argv);

#endif
