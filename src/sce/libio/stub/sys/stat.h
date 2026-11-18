#include <sys/types.h>
struct stat { unsigned int st_mode; long st_size; int st_blksize; };
#define S_IFMT 0170000
#define S_IFREG 0100000
#define S_ISCHR(m) (((m)&S_IFMT)==0020000)
#define S_ISDIR(m) (((m)&S_IFMT)==0040000)
