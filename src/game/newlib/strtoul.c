// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// newlib 1.9.0 libc/stdlib/strtoul.c _strtoul_r (0x3A9018); unsigned long is 64-bit on EE.
#include <errno.h>
#include <reent.h>

extern const char D_0045F039[];
#define CT(c) (D_0045F039[(unsigned)(c)])

// FUNCTION: GAME 0x3A9018
unsigned long func_003A9018(struct _reent *rptr, const char *nptr, char **endptr, int base)
{
    register const char *s = nptr;
    register unsigned long acc;
    register int c;
    register unsigned long cutoff;
    register int neg = 0, any, cutlim;

    do {
        c = *s++;
    } while (CT(c) & 8);
    if (c == '-') {
        neg = 1;
        c = *s++;
    } else if (c == '+')
        c = *s++;
    if ((base == 0 || base == 16) && c == '0' && (*s == 'x' || *s == 'X')) {
        c = s[1];
        s += 2;
        base = 16;
    }
    if (base == 0)
        base = c == '0' ? 8 : 10;
    cutoff = (unsigned long)-1 / (unsigned long)base;
    cutlim = (unsigned long)-1 % (unsigned long)base;
    for (acc = 0, any = 0;; c = *s++) {
        if (CT(c) & 4)
            c -= '0';
        else if (CT(c) & 3)
            c -= (CT(c) & 1) ? 'A' - 10 : 'a' - 10;
        else
            break;
        if (c >= base)
            break;
        if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
            any = -1;
        else {
            any = 1;
            acc *= base;
            acc += c;
        }
    }
    if (any < 0) {
        acc = (unsigned long)-1;
        rptr->_errno = ERANGE;
    } else if (neg)
        acc = -acc;
    if (endptr != 0)
        *endptr = (char *)(any ? (char *)s - 1 : nptr);
    return acc;
}
