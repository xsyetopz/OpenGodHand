#include <sys/types.h>
#ifdef __cplusplus
extern "C" {
#endif
off_t lseek(int,off_t,int);
ssize_t read(int,void*,size_t);
ssize_t write(int,const void*,size_t);
int close(int);
int isatty(int);
#ifdef __cplusplus
}
#endif
