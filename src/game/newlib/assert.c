// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// newlib 1.9.0 assertion failure (0x3A7B58): prints the message to stderr, then aborts.
#define fprintf fprintfX
#include <stdio.h>
#undef fprintf

extern const char D_0045F5C0[];
int fprintf(FILE *, const char *, ...) __asm__("func_003AE188");
void abort(void);

// FUNCTION: GAME 0x3A7B58
void __assert(const char *a, int b, const char *c)
{
    fprintf(_impure_ptr->_stderr, D_0045F5C0, c, a, b);
    abort();
}
