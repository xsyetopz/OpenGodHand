// Small units in 0x140000-0x150000.
extern "C" {
void *memcpy(void *, const void *, unsigned);
void *getMeshPtr__6cModeli(void *, int);
int getGold__9cCoreSave(void *);
void initAddGold__9cCoreSave(void *);
void func_001483C8(void *, int);
void func_002A9800(void *, void *);
}
extern char CoreSave[];

#ifdef NONMATCHING
// DRAFT: GAME 0x1415E8 - 7-9 words differ: gcc rotates the loop into bgezl and orders the sb stores 75 then 76
extern "C" void func_001415E8(char *p, int a)
{
    char **q = (char **)(p + 0x22F4);
    for (int i = 0x10; i >= 0; i--, q += 3) {
        char *o = *q;
        if (o) {
            o[0x76] = a;
            o[0x75] = 1;
        }
    }
}
#endif

// FUNCTION: GAME 0x1451A0
extern "C" void func_001451A0(char *self, void *src)
{
    memcpy(self + 0x3FA, src, *(short *)(self + 0x3B2));
    *(unsigned *)(self + 0x90) |= 0x40000000;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x148200 - 2 words differ: 0x28 and 0x24 float stores swap
extern "C" void func_00148200(float *p, float a, float b)
{
    p[8] = a;
    p[9] = b;
    p[15] = 0;
    p[0] = 1.0f;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 1.0f;
    p[6] = 0;
    p[7] = 0;
    p[11] = 0;
    p[12] = 0;
    p[13] = 0;
    p[14] = 0;
    p[10] = 1.0f;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x14D7D0 - 8 words differ: original computes (x<2)^1 with xori and branches
extern "C" void func_0014D7D0(char *self)
{
    char *m = (char *)getMeshPtr__6cModeli(self, 0);
    char *v[2];
    v[0] = *(char **)(m + 0x388);
    char *w = v[0];
    unsigned short x = *(unsigned short *)(w + 8);
    if ((x < 2) ^ 1)
        self[0x2BE] = 0x16;
    else
        self[0x2BE] = 0x18;
}
#endif

// FUNCTION: GAME 0x1494F8
extern "C" void func_001494F8(char *self, void *o)
{
    if (o) {
        *(int *)(self + 0x1C) = *(int *)(self + 0x1C) + 1;
        func_001483C8(o, 2);
        func_002A9800(self, o);
    }
}

// FUNCTION: GAME 0x143A90
extern "C" void func_00143A90(char *self)
{
    if (*(char **)(self + 0x94)) {
        char *s = CoreSave;
        *(int *)(self + 0x90) = getGold__9cCoreSave(s);
        *(int *)(*(char **)(self + 0x94) + 0x84) = getGold__9cCoreSave(s);
        initAddGold__9cCoreSave(s);
    }
}

// FUNCTION: GAME 0x1450A0
extern "C" void func_001450A0(char *self, void *src, short n)
{
    if (n >= 0x24)
        *(short *)(self + 0x3B2) = 0x23;
    else
        *(short *)(self + 0x3B2) = n;
    memcpy(self + 0x36C, src, *(short *)(self + 0x3B2) << 1);
    *(unsigned *)(self + 0x90) |= 0x40000000;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x1451E0 - 4 words differ: the -1/-2 tail uses movz with swapped constants (original movn)
extern "C" int func_001451E0(char *p)
{
    if (*(short *)(p + 0x41E) == 3 && *(short *)(p + 0x420) == 0) {
        int n = *(short *)(p + 0x422) + 1;
        if (n >= *(short *)(p + 0x3B2))
            return *(short *)(p + 0x36C);
        return *(short *)((p + n * 2) + 0x36C);
    }
    int r = -2;
    if (*(short *)(p + 0x41E))
        r = -1;
    return r;
}
#endif
