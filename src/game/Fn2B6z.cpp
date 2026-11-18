#ifdef NONMATCHING
extern unsigned D_00747A2C[];
extern int D_005E6908;
extern "C" int func_002BF700(char *);
extern "C" void func_002BF170(char *);
// DRAFT: GAME 0x2BF1A0
// 8 words differ: tail stores and the 0x40000000 or schedule in a different register order
extern "C" int openSave__9cSaveLoad10eSavePoint(char *self, int x)
{
    unsigned *g = D_00747A2C;
    if ((int)g[3] < 0 || (g[2] & 0x800)) {
        g[0x5C / 4] &= 0xBFFFFFFF;
        return 1;
    }
    if (!func_002BF700(self))
        return 0;
    func_002BF170(self);
    if (x != -1)
        D_005E6908 = x;
    g[0x5C / 4] |= 0x40000000;
    self[0] = 3;
    self[1] = 1;
    self[2] = 0;
    self[3] = 0;
    return 1;
}

extern char *g_Sce;
extern unsigned D_00747A30;
extern const char D_0044C0E0[], D_0044C118[], D_0044C150[], D_0044C170[];
extern "C" char *func_002C5028(char *, unsigned short);
extern "C" void func_002BE838(char *, char *, int);
extern "C" int sprintf(char *, const char *, ...);
// DRAFT: GAME 0x2BE708
// 9 words differ: ours emits movz for the lo clamp where the original uses nested slti branches
extern "C" void func_002BE708(char *self, unsigned short id)
{
    char buf[0x40];
    char *v = func_002C5028(g_Sce, id);
    if (!v)
        return;
    if (*(unsigned char *)(v + 0x10) != 1)
        return;
    unsigned hi = id >> 8;
    int lo = id & 0xFF;
    if (hi == 0) {
        if (lo >= 0x40) {
            if (lo < 0x46)
                lo = 0x40;
            else if (lo < 0x4E) {
                if (lo >= 0x4C)
                    lo = 0x40;
            }
        }
    }
    if (D_00747A30 & 0x400) {
        if (hi == 0xF)
            sprintf(buf, D_0044C0E0, hi);
        else
            sprintf(buf, D_0044C118, hi, lo);
    } else {
        if (hi == 0xF)
            sprintf(buf, D_0044C150, hi);
        else
            sprintf(buf, D_0044C170, hi, lo);
    }
    func_002BE838(self, buf, 0);
}
#endif
