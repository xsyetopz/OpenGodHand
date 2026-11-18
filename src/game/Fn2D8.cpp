// Small accessors in 0x2D8000-0x2DFFFF.

#include "cWorldLight.h"

// FUNCTION: GAME 0x002D8DE0
void cWorldLight::Gaibu_set_off() {
    *((char *)this + 0x16170) = 0x1E;
    *(int *)((char *)this + 0x16284) = 0;
}

extern "C" {

// FUNCTION: GAME 0x002D8FF8
int func_002D8FF8(int *a) { return a[0x78 / 4]; }

// FUNCTION: GAME 0x002D9BC8
void func_002D9BC8(void) {}

// FUNCTION: GAME 0x002D9BD0
void func_002D9BD0(void) {}

// FUNCTION: GAME 0x002D9BD8
void func_002D9BD8(void) {}

// FUNCTION: GAME 0x002D9D48
void func_002D9D48(int *a, int b) { a[1] = b; }

// FUNCTION: GAME 0x002D9000
char *func_002D9000(char *a, int b) { return a + (b * 0x70 + 0x80); }

// FUNCTION: GAME 0x002D9018
char *func_002D9018(char *a, int b) {
    if (b > 0x2F)
        b = 0x2F;
    int i = b;
    return a + (i * 0x14 + 0x7080);
}

// FUNCTION: GAME 0x002DF938
void func_002DF938(int a, int *b) {
    if (a != 0 && b != 0)
        b[0x58 / 4] = a;
}

// FUNCTION: GAME 0x002D9D50
void func_002D9D50(int a, unsigned t, unsigned *h, unsigned *m, unsigned *s) {
    unsigned hh = t / 0x1A5E0;
    t -= hh * 0x1A5E0;
    unsigned mm = t / 0x708;
    t -= mm * 0x708;
    unsigned ss = t / 30;
    if (h)
        *h = hh;
    if (m)
        *m = mm;
    if (s)
        *s = ss;
}

}
