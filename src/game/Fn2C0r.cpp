// More small functions from 0x2C0000-0x2D0000.
extern "C" void func_002CE488(char *a, int b);
extern "C" int *GetSeData__4cSndi(char *a, int b);
extern "C" void func_002CB7E8(char *a, int b);
extern "C" void func_0030F5A0(char *a);
extern "C" void func_002C0038(char *a);
extern "C" void func_002CE510(char *a, short b, int c);
extern "C" int func_002CDA38(char *a);
extern "C" void func_00375050(int a, int b);
extern "C" void func_002CE3E8(char *a);
extern char g_SceAt[];
extern char *g_SaveManager;
extern char *CoreSave;
extern unsigned D_00747A24;

// FUNCTION: GAME 0x2C2418
extern "C" int func_002C2418(char *u, unsigned flags)
{
    char *g = g_SceAt;
    if (*(int *)(g + 0x70) == 0) {
        if (flags & 0x10) {
            *(char **)(g + 0x70) = u + 0x5C;
            g[0x64] = u[0x7C];
        } else if (flags & 0x20) {
            g[0x64] = u[0x7D];
        } else {
            *(char **)(g + 0x70) = u + 0x5C;
        }
    }
    return 0;
}

// FUNCTION: GAME 0x2CBE18
extern "C" void func_002CBE18(char *self, int a)
{
    for (char *n = *(char **)(self + 0x1C); n; n = *(char **)(n + 4))
        func_002CE488(n, a);
}

// FUNCTION: GAME 0x2CB340
extern "C" void func_002CB340(char *self, int id)
{
    int *se = GetSeData__4cSndi(self, id);
    if ((unsigned)(se[0x3C / 4] - 0x200) < 0x100)
        func_002CB7E8(self, id);
    else
        func_002CB7E8(self, id);
}

// FUNCTION: GAME 0x2C1270
extern "C" void func_002C1270(char *self)
{
    char **p = (char **)(self + 0x74);
    unsigned i = 0;
    do {
        i++;
        if (*p) {
            func_0030F5A0(*p);
            *p = 0;
        }
        p++;
    } while (i < 8);
}

// FUNCTION: GAME 0x2C4A18
extern "C" void endCasinoBattle__9cScenario(void)
{
    func_002C0038(g_SaveManager);
    D_00747A24 &= 0xF7FFFFFF;
    *(unsigned *)(CoreSave + 0x14) &= 0xFBFFFFFF;
}

// FUNCTION: GAME 0x2C53C8
extern "C" void move__9cScrArray(char *self)
{
    int n = *(int *)(self + 8);
    if (n > 0) {
        if (*(unsigned char *)(self + 4)) {
            int c = *(int *)(self + 0xC) + 1;
            *(int *)(self + 0xC) = c;
            if (c < n)
                return;
        } else {
            int c = *(int *)(self + 0xC) - 1;
            *(int *)(self + 0xC) = c;
            if (c >= 0)
                return;
        }
        *(int *)(self + 8) = 0;
        *(int *)(self + 0xC) = 0;
    }
}

// FUNCTION: GAME 0x2CBE68
extern "C" void func_002CBE68(char *self, int a, int b)
{
    for (char *n = *(char **)(self + 0x1C); n; n = *(char **)(n + 4))
        func_002CE510(n, a, b);
}

// FUNCTION: GAME 0x2CE430
extern "C" void func_002CE430(char *self)
{
    if (func_002CDA38(self)) {
        if (*(unsigned *)(self + 0xC) & 1)
            func_00375050(*(int *)(self + 0x14), 0);
        else
            func_002CE3E8(self);
    }
}
