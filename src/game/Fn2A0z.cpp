// God Hand: small units in 0x2A0000-0x2C0000
extern "C" void __7cIDBase(void *);
extern "C" void func_002B1C80(void *);
extern "C" void func_002B1890(void *);
struct S2BDD90 { int pad0; unsigned char *p; unsigned short *t1; unsigned short *t2; };
extern "C" void DllLoad__3cMcb(void *, int);
extern "C" void DllRelease__3cMc(void *);
extern "C" void exit__9cTaskWork(void *);
extern "C" void func_0(void *);
extern char Mc;
extern char D_Ev297AA8[];
extern void *D_00752C04;
extern char D_005F38F0[];
// FUNCTION: GAME 0x2BF820
extern "C" void func_002BF820(int a, int b)
{
    if (b == 0xFFFF && a) {
        char *o = D_005F38F0;
        __7cIDBase(o + 0x20);
    }
}
// FUNCTION: GAME 0x2B1830
extern "C" void func_002B1830(char *s)
{
    *(unsigned short *)(s + 0xAE) = *(unsigned short *)(s + 0xA6);
    *(unsigned short *)(s + 0xB0) = *(unsigned short *)(s + 0xA8);
    *(float *)(s + 0x54) = 1.0f;
    *(float *)(s + 0x58) = 1.0f;
    *(short *)(s + 0x5C) = 1;
    *(short *)(s + 0x5E) = -0x14;
    func_002B1C80(s);
    func_002B1890(s);
}
// FUNCTION: GAME 0x2BDD90
extern "C" int func_002BDD90(S2BDD90 *s)
{
    unsigned char *p = s->p;
    int r = 0;
    int m;
    if (p[0])
        r = *(unsigned short *)((((p[0] - 1) << 2) + (int)s->t1) + 2);
    if (p[1]) {
        m = *(unsigned short *)((((p[1] - 1) << 2) + (int)s->t2) + 2);
        if (r < m)
            r = m;
    }
    return r;
}
// FUNCTION: GAME 0x2AE838
extern "C" void func_002AE838()
{
    DllLoad__3cMcb(&Mc, 0);
    func_0(D_Ev297AA8);
    func_0(D_Ev297AA8);
    DllRelease__3cMc(&Mc);
    exit__9cTaskWork(D_00752C04);
}
