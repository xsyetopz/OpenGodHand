// Small helpers in 0x1F0000-0x200000, over raw offsets.
extern "C" void __7cIDBase(void *);
extern unsigned char D_00569B80[];
extern unsigned char D_0056C380[];
extern int D_00568280;
extern "C" int sceWrite(int, const void *, int);
extern "C" int SdeSystemOutModeGet(void);
extern "C" void *memset(void *, int, unsigned);
extern "C" void func_001F45D8(void *);

// FUNCTION: GAME 0x1F5A58
extern "C" void *__7JukeBox(char *self)
{
    self[4] = 0;
    __7cIDBase(self + 0x30);
    *(int *)(self + 0x80) = 0;
    return self;
}

// FUNCTION: GAME 0x1F7798
extern "C" int *func_001F7798(char *self)
{
    int *p = (int *)(self + 0x104);
    for (unsigned i = 0; i < 8; i++, p = (int *)((char *)p + 0x44)) {
        if (((*p & 0x201) ^ 1) != 0)
            return p;
    }
    return 0;
}

// FUNCTION: GAME 0x1F7820
extern "C" void func_001F7820(char *self, int *key)
{
    int *p = (int *)(self + 0xF4);
    while (p) {
        int *n = (int *)p[1];
        if (n == key) {
            p[1] = n[1];
            n[1] = 0;
            return;
        }
        p = n;
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x1FE1E0 - 13 words: end/p registers and loop entry order differ
extern "C" unsigned char *func_001FE1E0(unsigned char *self)
{
    unsigned char *end = self + 0x3C00;
    unsigned char *p = self;
    do {
        if (p[0x4A] == 0)
            return p;
        p += 0x60;
    } while (p < end);
    return self + 0xAC00;
}
#endif

// FUNCTION: GAME 0x1FE310
extern "C" unsigned char *func_001FE310(unsigned char *self)
{
    unsigned char *p = self + 0x3C00;
    for (unsigned i = 0; i < 0x100; i++, p += 0x70) {
        if (p[0x4A] == 0)
            return p;
    }
    return self + 0xAC60;
}

// FUNCTION: GAME 0x1FE5A8
extern "C" unsigned char *func_001FE5A8(void)
{
    unsigned char *p = D_00569B80;
    for (unsigned i = 0; i < 0xA0; i++, p += 0x40) {
        if (p[0x2E] == 0)
            return p;
    }
    return 0;
}

// FUNCTION: GAME 0x1FE660
extern "C" unsigned char *func_001FE660(void)
{
    unsigned char *p = D_0056C380;
    for (unsigned i = 0; i < 0x200; i++, p += 0x40) {
        if (p[0x2E] == 0)
            return p;
    }
    return 0;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x1FF0D8 - 1 word: sra instead of dsrl on the 0x8 field
extern "C" int func_001FF0D8(char *p)
{
    if (*(int *)(p + 4) != 0)
        return 1;
    if ((*(int *)(p + 8) >> 2) & 1)
        return 0;
    return *(int *)(p + 0x10) != 0;
}
#endif

// FUNCTION: GAME 0x1F6E98
extern "C" int func_001F6E98(void *buf, int n)
{
    sceWrite(D_00568280, buf, n);
    return n;
}

// FUNCTION: GAME 0x1F9E28
extern "C" void func_001F9E28(char **self)
{
    if (*self)
        *(int *)(*self + 0x170) = SdeSystemOutModeGet();
}

#ifdef NONMATCHING
// DRAFT: GAME 0x1FCCC0 - 9 words: andi/addiu mask form and branch offsets differ
extern "C" void func_001FCCC0(char *p)
{
    if (*(short *)(p + 0x30)) {
        unsigned short n = *(unsigned short *)(p + 0x30) - 1;
        *(unsigned short *)(p + 0x30) = n;
        if (n == 0) {
            int *q = *(int **)(p + 0x28);
            *q &= ~2;
        }
    }
}
#endif

// FUNCTION: GAME 0x1F3580
extern "C" void *__16ColiseumEmSelect(char *self)
{
    memset(self, 0, 0x54);
    *(int *)(self + 0x54) = 0;
    func_001F45D8(self + 0x60);
    return self;
}
