#include <stddef.h>
#ifdef __cplusplus
extern "C" {
#endif
void *malloc(size_t);
void free(void*);
void *realloc(void*,size_t);
void abort(void);
void exit(int);
int atoi(const char*);
long strtol(const char*,char**,int);
int abs(int);
#ifdef __cplusplus
}
#endif
