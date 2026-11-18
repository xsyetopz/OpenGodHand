// COMPILER: ee-gcc2.9-991111
// SCE library varargs wrapper, ee-gcc 2.9-991111 -O2 -G0.
typedef void *va_list;
extern int func_0038D2B8(int, int, va_list, int);

// FUNCTION: GAME 0x38AF78
int func_0038AF78(int a, int b, ...)
{
    va_list ap = (va_list)((char *)__builtin_next_arg(b) - 0x30);
    return func_0038D2B8(a, b, ap, 0);
}
