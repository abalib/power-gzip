#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "nx.h"
#include "nxu.h"

#define GZIP_WRAPPER 0x01 //[GZIP header] [Deflate Stream] [CRC32] [ISIZE]
#define ZLIB_WRAPPER 0x02 //[ZLIB header] [Deflate Stream] [Adler32]
#define NO_WRAPPER 0x04   //[Deflate Stream]

static long pagesize = 65536;
typedef void gzip_dev;
typedef struct p9_simple_handle_t {
	gzip_dev *dev_handle; // device handle
			      // TODO DHT data structures
} p9_simple_handle_t;

extern void *nx_function_begin(int function, int pri);
extern int nx_function_end(void *handle);

/*open device*/
p9_simple_handle_t *p9open();

/*compress*/
int p9deflate(p9_simple_handle_t *handle, void *src, void *dst, int srclen,
	      int dstlen, char *fname, int flag);
/*decompress deflate buffer*/
int p9inflate(p9_simple_handle_t *handle, void *src, void *dst, int srclen,
	      int dstlen, int flag);
/*close the compressor*/
int p9close(p9_simple_handle_t *handle);
