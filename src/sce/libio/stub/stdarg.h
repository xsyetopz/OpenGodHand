#ifndef _STUB_STDARG_H
#define _STUB_STDARG_H
typedef char *__gnuc_va_list;
typedef __gnuc_va_list va_list;
#define __va_rounded_size(T) (((sizeof(T) + 3) / 4) * 4)
#define va_start(AP, LASTARG) __builtin_va_start(AP, LASTARG)
#define va_end(AP) __builtin_va_end(AP)
#define va_arg(AP, T) __builtin_va_arg(AP, T)
#endif
