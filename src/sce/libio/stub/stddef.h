#ifndef _STUB_STDDEF_H
#define _STUB_STDDEF_H
typedef unsigned int size_t;
typedef int ptrdiff_t;
#ifndef NULL
#define NULL 0
#endif
#define offsetof(T,M) ((size_t)&((T*)0)->M)
#endif
