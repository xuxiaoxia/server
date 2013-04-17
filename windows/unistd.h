#ifndef _TOKUWIN_UNISTD_H
#define _TOKUWIN_UNISTD_H
#include <io.h>
#include <stdio.h>

int
ftruncate(int fildes, int64_t offset);

int64_t
pwrite(int fildes, const void *buf, size_t nbyte, int64_t offset);

int64_t
pread(int fildes, void *buf, size_t nbyte, int64_t offset);

unsigned int
sleep(unsigned int);

int
usleep(unsigned int);

#endif
