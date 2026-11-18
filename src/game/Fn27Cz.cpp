extern "C" void func_002A8578(char *, float, int, int, int, int, int);
extern "C" void moveMotion__FP8cObjBase(void *);

#define B(o) (*(unsigned char *)(self + (o)))

// FUNCTION: GAME 0x27CE70
extern "C" void func_0027CE70(char *self)
{
    char *tb;
    int m;
    switch (B(0x2F6)) {
    case 0:
        m = B(0x2F7);
        if (m == 1) goto a;
        if (m < 2) goto a;
        if (m == 2) goto c;
    a:
        tb = *(char **)(self + 0x304);
        func_002A8578(self, 0.0f, *(int *)(tb + 0x78) + (int)tb, *(int *)(tb + 0x7C) + (int)tb, 0, 0, 0);
        goto e;
    c:
        tb = *(char **)(self + 0x304);
        func_002A8578(self, 0.0f, *(int *)(tb + 0x78) + (int)tb, *(int *)(tb + 0x7C) + (int)tb, 0, 0, 0);
    e:
        *(int *)(self + 0x15D4) = 0;
        B(0x2F6) = B(0x2F6) + 1;
    case 1:
        moveMotion__FP8cObjBase(self);
    }
}
