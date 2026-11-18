// Small helpers in 0x1F0000-0x200000, over raw offsets (continued from Fn1F0r.cpp).

extern "C" int func_001FD908(void *);

// FUNCTION: GAME 0x1FD988
extern "C" void func_001FD988(char *self, int a1)
{
    self[0x48] = a1;
    int r = func_001FD908(self);
    char *p = *(char **)(self + 0x3C);
    if (p) {
        do {
            *(int *)(*(char **)(p + 0x28) + 0x10) = r;
            p = *(char **)(p + 0x24);
        } while (p);
    }
}

extern "C" void *memset(void *, int, unsigned);
extern char D_00580D80[];

// FUNCTION: GAME 0x1FF800
extern "C" void *func_001FF800(char *self)
{
    *(int *)self = 0;
    *(int *)(self + 8) = 0;
    *(int *)(self + 0x10) = 0;
    *(int *)(self + 0x14) = 0;
    *(int *)(self + 0xC) = 0xC00;
    memset(D_00580D80, 0, 0x3000);
    return self;
}

extern "C" void setDoorJump__5cDoor(void *);

// FUNCTION: GAME 0x1FFF30
extern "C" void func_001FFF30(unsigned char *d, short a1, float *v, unsigned char a3, int t0, unsigned char t1, float f)
{
    *(short *)(d + 0x14) = a1;
    *(float *)(d + 4) = v[0];
    *(float *)(d + 8) = v[1];
    *(float *)(d + 0xC) = v[2];
    *(float *)(d + 0x10) = f;
    d[0x16] = 0xFF;
    d[0x17] = a3;
    *(int *)(d + 0x18) = t0;
    d[0x3A] = t1;
    setDoorJump__5cDoor(d);
}

extern "C" void func_001FE278(void *, void *);

// FUNCTION: GAME 0x1FE2B8
extern "C" void func_001FE2B8(char *self)
{
    char *p = self + 0x3C00;
    unsigned i = 0;
    do {
        func_001FE278(self, p);
        i++;
        p += 0x70;
    } while (i < 0x100);
}

extern "C" void ReleaseDamageGive__13cDamageManageP11cDamageGive(void *, void *);

// FUNCTION: GAME 0x1FE188
extern "C" void func_001FE188(char *self)
{
    char *p = self;
    char *end = self + 0x3C00;
    do {
        ReleaseDamageGive__13cDamageManageP11cDamageGive(self, p);
        p += 0x60;
    } while (p < end);
}

extern "C" void kill__9classFADE(void *);
extern char Fade[];

// FUNCTION: GAME 0x1F44E0
extern "C" void func_001F44E0(char *self)
{
    long l = *(unsigned *)(self + 0x54);
    long b = (l >> 1) & 1;
    if (b) {
        kill__9classFADE(Fade);
        *(int *)(self + 0x54) &= ~2;
    }
}

extern unsigned short D_003BF178[];

// FUNCTION: GAME 0x1FA148
extern "C" void setGameLevel__9cCoreSavei(char **self, int lvl)
{
    char *d = *self;
    if (d) {
        lvl -= 1;
        if (lvl < 0) lvl = 0;
        if (lvl > 4) lvl = 4;
        *(unsigned short *)(d + 0x1C) = *(unsigned short *)((char *)D_003BF178 + lvl * 4);
        (*self)[0x1E] = 2;
    }
}

extern "C" void func_001F29C0(char *, int, int);

// FUNCTION: GAME 0x1F30B8
extern "C" void func_001F30B8(char *self, int f)
{
    func_001F29C0(self, 2, f);
    *(int *)(self + 0x920) = 0;
    *(int *)(self + 0x924) = 0;
    if (f)
        *(int *)self |= 2;
    else
        *(int *)self &= ~2;
}

extern "C" int func_003078E0(int);

// FUNCTION: GAME 0x1FF470
extern "C" void func_001FF470(int *self, int a, int b)
{
    self[1] = 1;
    self[3] = func_003078E0(a);
    self[4] = b;
    self[8] = a;
    self[0] = 2;
}

extern "C" void SetNumber__12CustomIDWorki(char *, int);
extern "C" void func_001F4778(char *, int, int);

// FUNCTION: GAME 0x1F4C40
extern "C" void func_001F4C40(char *self, unsigned short i, int n, int f)
{
    if (i < 7) {
        SetNumber__12CustomIDWorki(self + (i * 0x7C + 0xC00), n);
        func_001F4778(self, i + 0x18, f);
    }
}

// FUNCTION: GAME 0x1F5210
extern "C" void func_001F5210(char *self, unsigned short i, int n, int f)
{
    if (i < 7) {
        SetNumber__12CustomIDWorki(self + (i * 0x7C + 0x2058), n);
        func_001F4778(self, i + 0x42, f);
    }
}


extern "C" char *getIDWork__7cIDBasei(char *, int);
// FUNCTION: GAME 0x1F6A20
extern "C" void func_001F6A20(unsigned char *self)
{
    if (self[1] == 2)
        *(unsigned *)(getIDWork__7cIDBasei((char *)self + 0x30, 10) + 0x2C) &= 0xDFFFFFFF;
    else
        *(unsigned *)(getIDWork__7cIDBasei((char *)self + 0x30, 10) + 0x2C) |= 0x20000000;
}

extern "C" int func_001FFA68(int);
extern "C" int func_001FFD98(int, char *);
// FUNCTION: GAME 0x1FF9C0
extern "C" int func_001FF9C0(int a, int, int *out)
{
    if (out) *out = 0;
    char *p = (char *)func_001FFA68(a);
    if (!p) return -1;
    if (out) *out = func_001FFD98(a, p);
    return *(int *)(p + 8);
}

extern "C" int func_002CB778(void *, int);
extern char Snd[];
// FUNCTION: GAME 0x1FF540
extern "C" int func_001FF540(char *self)
{
    int *p = (int *)(self + 0x24);
    for (int i = 0; i < 10; i++, p++) {
        if (!func_002CB778(Snd, *p)) return 0;
    }
    return 1;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x1F7AE8 (14 words: store scheduling of 0x3C)
extern "C" void func_001F7AE8(char *d)
{
    *(unsigned *)d &= 0xFFFFFFFEu;
    *(int *)(d + 0xC) = 1;
    *(int *)(d + 0x1C) = 0x31;
    *(int *)(d + 0x2C) = 0x1F;
    *(int *)(d + 0x40) = 0;
    *(int *)(d + 0x10) = 0;
    *(int *)(d + 0x14) = 0;
    *(int *)(d + 0x18) = 0;
    *(int *)(d + 0x24) = 0;
    *(int *)(d + 0x20) = 0;
    *(int *)(d + 0x28) = 0;
    *(short *)(d + 0x30) = 0;
    d[0x34] = 0;
    d[0x35] = 0;
    *(short *)(d + 0x32) = 0;
    d[0x36] = 0;
    *(int *)(d + 0x38) = 0;
    *(int *)(d + 0x3C) = 0;
}
#endif
