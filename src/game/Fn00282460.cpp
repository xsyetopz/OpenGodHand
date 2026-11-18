extern "C" void func_002A8578(void *, int, int, int, int, int, float);
extern "C" int moveMotion__FP8cObjBase(void *);

#define B(o) (*(unsigned char *)(self + (o)))

#ifdef NONMATCHING
// DRAFT: GAME 0x282460 - 57 differing words: original repeats a0/a3/f12/t0 arg setup per branch (276 bytes vs 244); tried per-branch calls, goto shared call, o reuse
extern "C" void func_00282460(char *self)
{
    switch (B(0x2F6)) {
    case 0: {
        int a, b;
        char *o;
        if (B(0x2F7)) {
            if (B(0x15B0)) {
                o = *(char **)(self + 0x304);
                a = *(int *)(o + 0xAC);
                b = *(int *)(o + 0xB4);
            } else {
                o = *(char **)(self + 0x304);
                a = *(int *)(o + 0xA0);
                b = *(int *)(o + 0xA8);
            }
            goto call;
        }
        if (B(0x15B0)) {
            o = *(char **)(self + 0x304);
            a = *(int *)(o + 0xAC);
            b = *(int *)(o + 0xB0);
        call:
            func_002A8578(self, a + (int)o, b + (int)o, 5, 0, 0, 0.0f);
        } else {
            o = *(char **)(self + 0x304);
            func_002A8578(self, *(int *)(o + 0xA0) + (int)o, *(int *)(o + 0xA4) + (int)o, 5, 0, 0, 0.0f);
        }
        B(0x2F6)++;
    }
    case 1:
        if (moveMotion__FP8cObjBase(self)) {
            B(0x2F4) = 0;
            B(0x2F5) = 0;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
    }
}
#endif
