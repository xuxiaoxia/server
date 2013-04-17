/* Test bread_backwards to make sure it can read backwards even for large files. */

#include "toku_portability.h"

#include <assert.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "../brttypes.h"
#include "../bread.h"

#define FNAME "test1305.data"

// THe buffer size in units of 64-bit integers.
#define N_BIGINTS (1<<20)
#define BIGINT_SIZE (sizeof(u_int64_t))
// How big is the readback buffer (in 8-bit integers)?
#define READBACK_BUFSIZE (1<<20)


static void
test (u_int64_t fsize) {
    unlink(FNAME);
    // Create a file of size fsize.  Fill it with 8-byte values which are integers, in order)
    assert(fsize%(N_BIGINTS*sizeof(u_int64_t)) == 0); // Make sure the fsize is a multiple of the buffer size.
    u_int64_t i = 0;
    {
	int fd = open(FNAME, O_CREAT+O_RDWR+O_BINARY, 0777);
	assert(fd>=0);
	u_int64_t buf[N_BIGINTS];
	while (i*BIGINT_SIZE < fsize) {
	    int j;
	    for (j=0; j<N_BIGINTS; j++) {
		buf[j] = i++;
	    }
	    int r = write(fd, buf, N_BIGINTS*BIGINT_SIZE);
	    assert(r==N_BIGINTS*BIGINT_SIZE);
	}
	{ int r = close(fd); assert(r==0); }
    }
    assert(i*BIGINT_SIZE == fsize);
    // Now read it all backward
    {
	int fd = open(FNAME, O_RDONLY+O_BINARY);  	assert(fd>=0);
	BREAD br = create_bread_from_fd_initialize_at(fd, fsize, READBACK_BUFSIZE);
	while (bread_has_more(br)) {
	    assert(i>0);
	    i--;
	    u_int64_t storedi;
	    { int r = bread_backwards(br, &storedi, sizeof(storedi)); assert(r==sizeof(storedi)); }
	    assert(storedi==i);
	}
	assert(i==0);
	{ int r=close_bread_without_closing_fd(br); assert(r==0); }
	{ int r=close(fd); assert(r==0); }
    }
    //printf("Did %" PRIu64 "\n", fsize);
    //system("ls -l " FNAME);
    unlink(FNAME);
}

int main (int argc __attribute__((__unused__)), char *argv[] __attribute__((__unused__))) {
    test(1LL<<23);
    test(1LL<<30);
    test(1LL<<31);
    test(1LL<<32);
    test(1LL<<33);
    return 0;
}
