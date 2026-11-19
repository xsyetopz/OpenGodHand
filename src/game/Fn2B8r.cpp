extern int D_00747A80;

// FUNCTION: GAME 0x2BF708
extern "C" void func_002BF708(char *self)
{
    *(int *)(self + 0x70) = D_00747A80;
    D_00747A80 |= 0x80000000;
    D_00747A80 |= 0x40000000;
    D_00747A80 |= 0x20000000;
    D_00747A80 |= 0x10000000;
    D_00747A80 |= 0x8000000;
    D_00747A80 |= 0x4000000;
    D_00747A80 |= 0x2000000;
    D_00747A80 |= 0x1000000;
    D_00747A80 |= 0x800000;
    D_00747A80 |= 0x400000;
    D_00747A80 |= 0x200000;
    D_00747A80 |= 0x100000;
}

extern int D_00747A78;
struct U8 { long v; } __attribute__((packed));

// FUNCTION: GAME 0x2BF790
extern "C" void func_002BF790(char *self)
{
    *(U8 *)(self + 0x74) = *(U8 *)&D_00747A78;
    D_00747A78 &= 0xFDFFFFFF;
    D_00747A78 |= 0x80000000;
    D_00747A78 |= 0x40000000;
    D_00747A78 |= 0x80000000;
    D_00747A78 |= 0x20000;
    D_00747A78 |= 0x10002000;
    D_00747A78 |= 0x40000;
    D_00747A78 |= 0x8000000;
    D_00747A78 |= 0x800000;
}

extern "C" void func_002B00A0(char *);
extern "C" void func_002B0208(char *);
extern "C" void func_002B0420(char *);

// DRAFT: GAME 0x2B0028
// diff: 6 words, a1 vs a2 for the 0x9400 constant and the lw/lhu/andi chain; tried case orders ACB (9 words) and BAC (23), typed unsigned short * local (6), and earlier forms
// diff: 6 words, register choice for the lw/lhu/andi chain (v0/v1 vs a2); switch layout matches, ~12 forms tried; callee int/void combos and typed locals (int/long/unsigned) no effect
// (temps, struct members, extra unused param, if-chain); original uses a2 for 0x9400, i.e. a1 held by another pseudo
#ifdef NONMATCHING
extern "C" void func_002B0028(char *self)
{
    switch (**(unsigned short **)(self + 0x64) & 0xFF00) {
    case 0xA800: func_002B00A0(self); break;
    case 0x9300: func_002B0208(self); break;
    case 0x9400: func_002B0420(self); break;
    }
}
#endif

extern "C" void func_002B2580(char *);
extern "C" int func_002B2588(char *);
extern "C" void func_002B2E80(char *);

// FUNCTION: GAME 0x2B2500
extern "C" int func_002B2500(char *self)
{
    switch (*(unsigned char *)(self + 0xD)) {
    case 0:
        func_002B2580(self);
        *(unsigned char *)(self + 0xD) += 1;
    case 1:
        if (!func_002B2588(self)) return 0;
        func_002B2E80(self);
        int r = 1;
        *(char *)(self + 0xD) = 0;
        *(char *)(self + 0xC) = r;
        *(char *)(self + 0xE) = 0;
        *(char *)(self + 0xF) = 0;
        return r;
    }
}

extern char *Message;
extern "C" char *getMessageAddr__C8cMessageUs(char *, unsigned short);

// FUNCTION: GAME 0x2B0EB8
extern "C" int func_002B0EB8(char *self, unsigned short *a)
{
    unsigned short *p = (unsigned short *)getMessageAddr__C8cMessageUs(Message, 4);
    unsigned short k = *a;
    for (unsigned i = 0; i < 10; i++, p++)
        if (k == *p) return 1;
    return 0;
}

extern "C" int func_002BB068(char *, int);
extern "C" char *func_002BB098(char *);

// FUNCTION: GAME 0x2BB0C8
extern "C" int func_002BB0C8(char *self, int a, int b)
{
    int *e = (int *)func_002BB068(self, a);
    if (e) {
        e[1] = b;
    } else {
        e = (int *)func_002BB098(self);
        if (!e) return 0;
        e[0] = a;
        e[1] = b;
    }
    return 1;
}

extern "C" int func_002AEF90(char *);
extern "C" int func_002B45F8(char *, int, int);
extern "C" void func_002B43B0(char *);
extern "C" void func_002B45E8(char *);

// FUNCTION: GAME 0x2B3B70
extern "C" int func_002B3B70(char *self)
{
    if (!func_002AEF90(Message) || !func_002B45F8(self, *(int *)(self + 0x8C), 0x8000))
        func_002B43B0(self);
    func_002B45E8(self);
    *(char *)(self + 0xD) = 0;
    *(char *)(self + 0xC) = 6;
    *(char *)(self + 0xE) = 0;
    *(char *)(self + 0xF) = 0;
    return 2;
}

// FUNCTION: GAME 0x2B2B08
extern "C" int func_002B2B08(char *self)
{
    *(char *)(self + 0x70) = 2;
    *(char *)(self + 0xA4) = 3;
    *(int *)(self + 0x18) = 0;
    *(char *)(self + 0x3C) = 0;
    unsigned short h = *(unsigned short *)(*(char **)(self + 0x8C) + 2);
    *(short *)(self + 0x62) = h == 0xFFFF ? 0 : h;
    h = *(unsigned short *)(*(char **)(self + 0x8C) + 4);
    *(short *)(self + 0xA6) = h == 0xFFFF ? 0x100 : h;
    h = *(unsigned short *)(*(char **)(self + 0x8C) + 6);
    *(short *)(self + 0xA8) = h == 0xFFFF ? 0xE0 : h;
    return 0;
}
