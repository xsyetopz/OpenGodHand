// Small helpers in 0x1F0000-0x200000, over raw offsets (continued from Fn1F0s.cpp).

extern "C" void setDoorJump__5cDoor(void *);

typedef void (*VFn)(char *, int);
// FUNCTION: GAME 0x1FD820
extern "C" void func_001FD820(char *self, int a1)
{
    char *p = *(char **)(self + 0x3C);
    if (p) {
        do {
            char *o = *(char **)(*(char **)(p + 0x28) + 0x34);
            char *vt = *(char **)(o + 0x100);
            ((VFn) * (int *)(vt + 0x3C))(o + *(short *)(vt + 0x38), a1);
            p = *(char **)(p + 0x24);
        } while (p);
    }
}


extern char Door[];
// FUNCTION: GAME 0x1F9ED0
extern "C" void func_001F9ED0(char **self)
{
    if (*self) {
        char *p = Door;
        char *d = p + 0x1C;
        *(unsigned short *)(*self + 0x15A) = *(unsigned short *)(d + 0x10);
        *(float *)(*self + 0x15C) = *(float *)(p + 0x1C);
        *(float *)(*self + 0x160) = *(float *)(d + 4);
        *(float *)(*self + 0x164) = *(float *)(d + 8);
        *(float *)(*self + 0x168) = *(float *)(d + 0xC);
        (*self)[0x158] = d[0x12];
        (*self)[0x159] = d[0x13];
        *(int *)(*self + 0x16C) = *(int *)(d + 0x14);
    }
}

extern unsigned short D_00747A50;
// FUNCTION: GAME 0x1FFEB8
extern "C" void func_001FFEB8(unsigned char *d, unsigned short a1, float *v, unsigned char a3, int t0, unsigned char t1, float f)
{
    *(unsigned short *)(d + 0x14) = (a1 == D_00747A50) ? 0xFFFF : a1;
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


extern char Door[];
extern "C" void func_002009B0(char *, char *);
// FUNCTION: GAME 0x1F9F50
extern "C" void func_001F9F50(char **self)
{
    char *s = *self;
    if (s) {
        struct { float x, y, z, w; unsigned short h; unsigned char b0, b1; int i; } t;
        t.h = *(unsigned short *)(s + 0x15A);
        t.x = *(float *)(s + 0x15C);
        t.y = *(float *)(s + 0x160);
        t.z = *(float *)(s + 0x164);
        t.w = *(float *)(s + 0x168);
        t.b0 = s[0x158];
        t.b1 = s[0x159];
        t.i = *(int *)(s + 0x16C);
        func_002009B0(Door, (char *)&t);
    }
}

// FUNCTION: GAME 0x1FC650
extern "C" void getAllStageTime__9cCoreSavePUiN21(char **self, unsigned *h, unsigned *m, unsigned *s)
{
    char *d = *self;
    if (d) {
        unsigned t = *(unsigned *)(d + 0xBBC);
        unsigned hh = t / 108000;
        t -= hh * 108000;
        unsigned mm = t / 1800;
        t -= mm * 1800;
        unsigned ss = t / 30;
        if (h) *h = hh;
        if (m) *m = mm;
        if (s) *s = ss;
    }
}

extern "C" int ckClearStage__9cCoreSaveUs(void *, unsigned short);
extern char CoreSave[];
// FUNCTION: GAME 0x1FC020
extern "C" char func_001FC020(int *self)
{
    if (!*self) return 0;
    unsigned char i = 1;
    while (i < 8) {
        if (!ckClearStage__9cCoreSaveUs(CoreSave, i)) break;
        i++;
    }
    return i;
}

#ifdef NONMATCHING
extern "C" int func_002CB278(void *);
extern char Snd[];
// DRAFT: GAME 0x1FF4D0 (3 words: original keeps the range test in v0, compiled reuses a1)
extern "C" void func_001FF4D0(char *self, unsigned id)
{
    unsigned t = id - 0x200;
    if (t < 0xFF) {
        int r = func_002CB278(Snd);
        char *a = self + 0x24;
        *(int *)(a + (*(int *)(self + 0x18) << 2)) = r;
        if (*(int *)(a + (*(int *)(self + 0x18) << 2)) != -1)
            *(int *)(self + 0x18) += 1;
    }
}
#endif
