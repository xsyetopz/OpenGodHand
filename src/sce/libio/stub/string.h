#include <stddef.h>
#ifdef __cplusplus
extern "C" {
#endif
void *memcpy(void*,const void*,size_t);
void *memset(void*,int,size_t);
void *memchr(const void*,int,size_t);
void *memmove(void*,const void*,size_t);
size_t strlen(const char*);
char *strcpy(char*,const char*);
char *strchr(const char*,int);
int strcmp(const char*,const char*);
int memcmp(const void*,const void*,size_t);
char *strncpy(char*,const char*,size_t);
char *strerror(int);
#ifdef __cplusplus
}
#endif
