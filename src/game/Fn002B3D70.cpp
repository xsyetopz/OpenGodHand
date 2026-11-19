extern "C" void func_002B4768(char *, char *, char *, int);
extern "C" void func_00297BF8(char *);
extern char Event[];
extern int D_003C2550;
extern long D_003C3D48;
extern int D_00747A84;
extern "C" void func_002CB070(char *);
extern "C" void func_002CBC58(char *, int, int);
extern "C" void func_002CD4A8(char *, float);
extern "C" void func_002CD500(char *, int, float);
extern "C" void func_002CE430(char *);
extern "C" int func_002CB3A8(char *, int);
extern "C" void *GetSeData__4cSndi(char *, int);
extern "C" int IsAlive__7cSeData(void *);
extern "C" void *func_002CBEC0(char *);
extern "C" int func_002CDD18(void *, int, int, void *, void *, unsigned, int);
extern int D_0044CE48[12];

#ifdef NONMATCHING
// DRAFT: GAME 0x2B3D70
// 43 differing words: lui order, dsrl/sra form, split and-mask. Variants vd, vg, vf tried and worse.
extern "C" void func_002B3D70(char *self)
{
    switch ((unsigned char)self[0xD]) {
    case 0:
        if (*(unsigned short *)(self + 0x2E) == 0) {
            self[0xB2] = 0;
            *(int *)(self + 0x14) |= 0x80;
            self[0xD]++;
        case 1:
            self[0xB2]++;
            D_003C2550++;
            if (!(((unsigned long)D_00747A84 >> 4) & 1)) {
                if (*(int *)(self + 0x34) != 1) {
                    char *sys = (char *)&D_00747A84 - 0x1790;
                    if ((*(long *)(sys + 0x178) & D_003C3D48) || (*(unsigned *)(sys + 0x1A0) & 0x10000000)) {
                        goto block_13;
                    }
                } else if (D_003C2550 >= 0x5A) {
block_13:
                    D_003C2550 = 0;
                    *(int *)(self + 0x14) = *(int *)(self + 0x14) & ~0x80 & ~1;
                    func_002B4768(self, self + 0x90, self + 0x8C, -2);
                    self[0xF] = 0;
                    self[0xC] = 2;
                    self[0xD] = 0;
                    self[0xE] = 0;
                    if (D_00747A84 & 0x20000000) {
                        func_00297BF8(Event);
                    }
                }
            }
        }
        break;
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x2CAA00
// 26 differing words: and-chain register assignment and second list-walk tail differ. Variants ve, vf, vg, vh gave no gain.
extern "C" void func_002CAA00(char *self)
{
    int i = 0;
    int s0 = 0x10000;
    int t;
    char *p;
    int a = *(int *)(self + 0xB0) | 0x800000;
    int b = *(int *)(self + 0xAC) | 0x800000;

    a &= 0xFFDFFFFF;
    b &= 0xFFDFFFFF;
    a &= 0xFFEFFFFF;
    b &= 0xFFEFFFFF;
    a &= 0xFFF7FFFF;
    b &= 0xFFF7FFFF;
    *(int *)(self + 0xB0) = a;
    *(int *)(self + 0xAC) = b;
    do {
        func_002CBC58(self, i, 10);
        t = s0;
        i = t >> 16;
        s0 = t + 0x10000;
    } while (i < 0x34);

    p = *(char **)(self + 0x1C);
    if (p != 0) {
        do {
            if (*(int *)(p + 0xC) & 1) {
            } else {
                func_002CE430(p);
            }
            p = *(char **)(p + 4);
        } while (p != 0);
    }

    p = *(char **)(self + 0x18);
    if (p != 0) {
        do {
            if (((unsigned char *)p)[0x5F] != 0 || ((unsigned char *)p)[0x61] != 0 || (*(int *)(p + 0x98) & 0x10000)) {
                func_002CD4A8(p, 20.0f);
                *(int *)(p + 0x98) = *(int *)(p + 0x98) | 0x100;
            } else {
                func_002CD500(p, 0x100000, 20.0f);
            }
            p = *(char **)(p + 0x88);
        } while (p != 0);
    }

    *(int *)(self + 0x128) = -2;
    func_002CB070(self);
}
#endif

// FUNCTION: GAME 0x2CBA48
extern "C" int SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(char *self, short blk, short arg2, char *obj, char *obj2, char *parts, unsigned flags, int flag2)
{
    short sel = blk;
    int s1;
    unsigned i;
    int *q;
    void *t;

    if (sel == 1) {
        if (obj2 != 0) {
            s1 = func_002CB3A8(self, *(int *)(obj2 + 0x564));
            if (s1 <= 0) {
                s1 = *(unsigned short *)(obj2 + 0x300);
            }
        } else {
            s1 = func_002CB3A8(self, *(int *)(obj + 0x564));
            if (s1 <= 0) {
                s1 = *(unsigned short *)(obj + 0x300);
            }
        }
        i = 0;
        q = D_0044CE48;
        do {
            if (*(int *)((char *)GetSeData__4cSndi(self, *q) + 0x3C) == s1) {
                sel = (short)*q;
            }
            i++;
            q++;
        } while (i < 12);
    }
    if (IsAlive__7cSeData(GetSeData__4cSndi(self, sel)) != 0) {
        t = func_002CBEC0(self);
        if (t != 0) {
            return func_002CDD18(t, sel, arg2, obj, parts, flags, flag2);
        }
        return 0;
    }
    return 0;
}
