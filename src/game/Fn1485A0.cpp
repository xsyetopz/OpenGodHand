extern "C" void func_00148F50(char *, void *, int);
extern "C" void func_001490B0(char *, void *, int);
extern "C" void func_00154A90(char *, int, int);
extern "C" int func_00155138();
extern "C" int func_00155248(char *);
extern "C" void func_00155358(char *, int, int);

// FUNCTION: GAME 0x1485A0
extern "C" int func_001485A0(char *self, char *p, int a2, int a3, int t0, int t1, int t2)
{
    int r = t2;
    char *sp0;
    *(int *)(self + 0x400) = a2;
    *(char *)(self + 0x384) = 0;
    *(int *)(self + 0x380) = a3;
    *(int *)(self + 0x410) = 0;
    *(char **)(self + 0x388) = p;
    sp0 = p;
    unsigned short h = *(unsigned short *)(p + 8);
    *(char *)(self + 0x386) = h;
    unsigned short h2 = *(unsigned short *)(p + 8);
    int c = h2 >= 2;
    if (c) {
        int v = func_00155138();
        *(int *)(self + 0x408) = r;
        func_00154A90(self, r, 0);
        r += v;
    } else {
        int v = func_00155248(self);
        *(int *)(self + 0x408) = r;
        func_00155358(self, r, 0);
        r += v;
    }
    if (a3 & 0x1000000)
        func_00148F50(self, &sp0, t1);
    else
        func_001490B0(self, &sp0, t1);
    return r;
}
