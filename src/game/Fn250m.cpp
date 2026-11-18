// Mid-size units in 0x250000-0x270000.
#include "game/cEm00Fn240Decls.h"

extern unsigned short D_00747A50;

// FUNCTION: GAME 0x268408
extern "C" int func_00268408(char *self)
{
    int s = *(int *)(self + 0x564);
    if (s < 0x20F)
        return 0;
    if (s >= 0x211 && s != 0x226)
        return 0;
    int k = *(int *)(self + 0x474);
    if (k != 1 && k != 9)
        return 0;
    if (D_00747A50 != 0x700)
        return 0;
    if (*(float *)(self + 0x1744) > 0.0f)
        return 0;
    B(0x2F4) = 0;
    B(0x2F5) = 0x86;
    B(0x2F6) = 0;
    B(0x2F7) = 0;
    return 1;
}

extern "C" void SetEffectParts__F12eEffDataType6eEffIdP4cObjiffffi(int, int, void *, int, float, float, float, float, int);
extern "C" void KillEffect__FPC4cObji13eEspEraseMode(void *, int, int);

// FUNCTION: GAME 0x268508
extern "C" void func_00268508(char *self)
{
    unsigned f = *(unsigned *)(self + 0x16D0);
    if (*(float *)(self + 0x17CC) > 0.0f) {
        if (!(f & 0x80)) {
            *(unsigned *)(self + 0x16D0) = f | 0x80;
            if (*(int *)(self + 0x564) != 0x223)
                SetEffectParts__F12eEffDataType6eEffIdP4cObjiffffi(0, 4, self, 4, 0.0f, 0.0f, 0.0f, 1.0f, 3);
            else
                SetEffectParts__F12eEffDataType6eEffIdP4cObjiffffi(0, 4, self, 6, 0.0f, 0.0f, 0.0f, 1.0f, 3);
        }
    } else if (f & 0x80) {
        *(unsigned *)(self + 0x16D0) = f & 0xFFFFFF7F;
        KillEffect__FPC4cObji13eEspEraseMode(self, 3, 2);
    }
}

extern "C" void func_001CFE88(void *, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x26BAD8 - 14 words differ: original tests (st ^ 0x211) with lw/xori and keeps the loop counter in s2, index in s1 differently scheduled
extern "C" void func_0026BAD8(char *self, unsigned n, int p)
{
    if (!(*(int *)(self + 0x564) ^ 0x211) && n != 0) {
        unsigned i = 0;
        unsigned cnt = 0;
        void **q = (void **)(self + 0x710);
        do {
            if (*q) {
                cnt++;
                func_001CFE88(*q, p);
                *q = 0;
            }
            q++;
        } while (++i < 8 && cnt < n);
    }
}
#endif

// FUNCTION: GAME 0x26EA50
extern "C" int func_0026EA50(char *self)
{
    if (*(float *)(self + 0x1704) <= 0.0f)
        return 0;
    g_CollSolidManage.SetActive((cGameObj *)self, 0);
    float t = *(float *)(self + 0x1704) - 0.02f;
    float u = 1.0f - t;
    *(float *)(self + 0x1704) = t;
    *(float *)(self + 0x24C) = u;
    if (u >= 1.0f) {
        *(float *)(self + 0x24C) = 1.0f;
        *(unsigned *)(self + 0x250) &= 0xFFFFFFEF;
    } else {
        *(unsigned *)(self + 0x250) |= 0x10;
    }
    return 1;
}

extern "C" int func_0026F328(void *);
extern "C" void func_0026ECD0(void *, int);

// FUNCTION: GAME 0x26F200
extern "C" int func_0026F200(char *self)
{
    if (*(float *)(self + 0x16C0) > 0.0f)
        return 0;
    if (!func_0026F328(self))
        return 0;
    if (*(unsigned *)(self + 0x16D0) & 0x40000)
        return 0;
    if (*(short *)(self + 0x54A) <= 0)
        return 0;
    int st = *(int *)(self + 0x564);
    if (st == 0x256 && D_00747A50 == 0x406)
        return 0;
    if (st == 0x218 && D_00747A50 == 1)
        return 0;
    func_0026ECD0(self, 1);
    return 1;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x257E90 - structure matches; ~2 real words differ (shifts the rest): original reloads 0x304 in the else arm of both setup branches and keeps a/b in v1/a0 before the addu, ours hoists the load and uses a1/a2
extern "C" void func_00257E90(char *self)
{
    switch (B(0x2F6)) {
    case 0: {
        unsigned m = func_00276468(self) & 0xFFFF;
        int o;
        int a, b;
        if (*(unsigned short *)(self + 0x3AC) & 0x200) {
            o = *(int *)(self + 0x304);
            a = *(int *)(o + 0x1CE8);
            b = *(int *)(o + 0x1CEC);
        } else {
            o = *(int *)(self + 0x304);
            a = *(int *)(o + 0x1CF0);
            b = *(int *)(o + 0x1CF4);
        }
        int a1 = a + o;
        int a2 = b + o;
        func_002A8578(self, a1, a2, 3, 0.0f, m, 0);
        if (irand__Fv() & 1)
            *(int *)(self + 0x5F0) = 5;
        else
            *(int *)(self + 0x5F0) = (unsigned)irand__Fv() % 0x5A + 0x1E;
        B(0x2F6)++;
    }
    case 1: {
        moveMotion((cObjBase *)self);
        int c = *(int *)(self + 0x5F0);
        if (c > 0)
            *(int *)(self + 0x5F0) = c - 1;
        else
            B(0x2F6) = 2;
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
        break;
    }
    case 2: {
        unsigned m = func_00276468(self) & 0xFFFF;
        int o;
        int a, b;
        if (*(unsigned short *)(self + 0x3AC) & 0x200) {
            o = *(int *)(self + 0x304);
            a = *(int *)(o + 0x1D40);
            b = *(int *)(o + 0x1D44);
        } else {
            o = *(int *)(self + 0x304);
            a = *(int *)(o + 0x1D48);
            b = *(int *)(o + 0x1D4C);
        }
        int a1 = a + o;
        int a2 = b + o;
        func_002A8578(self, a1, a2, 3, 0.0f, m, 0);
        B(0x2F6)++;
    }
    case 3:
        if (moveMotion((cObjBase *)self)) {
            if (func_0026F1D8(self)) {
                Snd.SeCall(0, 0x8C, self, 0, 0, 0, 0);
                func_00270C78(self);
            } else {
                func_002705D8(self);
            }
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
}
#endif
