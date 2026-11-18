// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// newlib 1.9.0 stdio: scans a format string for a floating-point conversion (E G L e f g) and dispatches (0x3A9D88).
#include <stdio.h>

int float_(struct _reent *, FILE *, char *, void *) __asm__("func_003A9E58");
int nofloat_(struct _reent *, FILE *, char *, void *) __asm__("func_003AB188");

// FUNCTION: GAME 0x3A9D88
int func_003A9D88(FILE *fp, char *fmt, void *ap)
{
    char *s = fmt;

    while (*s) {
        if (*s == '%' && s[1]) {
            s++;
            while (*s < 'A' && s[1])
                s++;
            switch (*s) {
            case 'E':
            case 'G':
            case 'L':
            case 'e':
            case 'f':
            case 'g':
                return float_(fp->_data, fp, fmt, ap);
            }
        }
        s++;
    }
    return nofloat_(fp->_data, fp, fmt, ap);
}
