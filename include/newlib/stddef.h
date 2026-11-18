#ifndef _STDDEF_H
#define _STDDEF_H
typedef unsigned int size_t;
typedef int ptrdiff_t;
typedef int wchar_t;
#define NULL ((void *)0)
#define offsetof(T, m) ((size_t)&((T *)0)->m)
#endif
