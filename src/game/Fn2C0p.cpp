// Unnamed units in 0x2C0000-0x2D0000 (se data scan, table init).
extern "C" int IsAlive__7cSeData(void *);
extern "C" void func_002CC4A0(void *);
extern char D_005FFD80[], D_00601180[], D_005FEFF0[], D_005FFCF0[];

// FUNCTION: GAME 0x2CC0C0
extern "C" int func_002CC0C0(char *self, int val)
{
    for (int i = 20; i < 52; i++) {
        int off = i << 6;
        if (IsAlive__7cSeData(*(char **)(self + 0x3C) + off) == 1 && *(int *)(*(char **)(self + 0x3C) + off + 0x10) == val)
            return i;
    }
    return -1;
}

// FUNCTION: GAME 0x2C9C88
extern "C" char *func_002C9C88(char *self)
{
    *(char **)(self + 0x34) = D_005FFD80;
    *(char **)(self + 0x38) = D_00601180;
    *(char **)(self + 0x3C) = D_005FEFF0;
    *(char **)(self + 0x40) = D_005FFCF0;
    *(int *)(self + 0x18) = 0;
    *(int *)(self + 0x1C) = 0;
    char *p = self + 0x160;
    int n = 15;
    do {
        func_002CC4A0(p);
        n--;
        p += 8;
    } while (n != -1);
    return self;
}

extern "C" void *func_002CC4C8(void *, int);
extern "C" int func_002CDA38(void *);
extern "C" void func_002CDA48(void *);
extern "C" int func_002CC050(void *);
extern "C" void *GetSeData__4cSndi(void *, int);
extern "C" int func_002CF760(void *, int, int, int);

// FUNCTION: GAME 0x2CBEC0
extern "C" void *func_002CBEC0(void *self)
{
    for (int i = 0; i < 64; i++) {
        if (func_002CDA38(func_002CC4C8(self, i)) == 0) {
            func_002CDA48(func_002CC4C8(self, i));
            return func_002CC4C8(self, i);
        }
    }
    return 0;
}

// FUNCTION: GAME 0x2CB6E0
extern "C" int func_002CB6E0(void *self, int a1)
{
    int r = func_002CC0C0((char *)self, a1);
    if (r != -1)
        return r;
    r = func_002CC050(self);
    if (r != -1) {
        if (func_002CF760(GetSeData__4cSndi(self, r), r, a1, 0x7FFFFFFF) == 0)
            return -1;
    }
    return r;
}
