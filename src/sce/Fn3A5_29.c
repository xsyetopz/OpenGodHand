// COMPILER: ee-gcc2.9-991111

extern int D_003F86A0;
extern void SignalSema(int);
extern int func_003B63A0(void);
extern void func_003B63F0(void);
extern int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);
#define R32(a) (*(volatile unsigned int *)(a))

extern char D_0045E400[];
extern void func_0039C390(void *, char *);
#define F(s, o) (*(int *)((char *)(s) + (o)))

#ifdef NONMATCHING
// DRAFT: GAME 0x399D70
// diff: 2 words (lui/ori constant scheduling)
void func_00399D70(char *s)
{
    R32(0x10002010) = (R32(0x10002010) & 0xFF7FFFFF) | 0x800000;
    if (F(s, 0x87C) == 0) {
        F(s, 0x830) = 0x70003600;
        F(s, 0x5A0) = 0x70000000;
        F(s, 0x5A4) = 0x70001800;
        F(s, 0x6E0) = 0x70001B00;
        F(s, 0x6E4) = 0x70003300;
        F(s, 0x820) = 0;
    } else if (F(s, 0x87C) == 1) {
        F(s, 0x830) = (int)(s + 0xE80);
        F(s, 0x5A4) = ((int)(s + 0x880) & 0xFFFFFFF) | 0x30000000;
        F(s, 0x6E4) = ((int)(s + 0xB80) & 0xFFFFFFF) | 0x30000000;
        F(s, 0x5A0) = 0;
        F(s, 0x6E0) = 0;
        F(s, 0x820) = 0;
    } else
        func_0039C390(s, D_0045E400);
}
#endif

extern int D_003F9840[];
extern volatile int D_003F86A0v __asm__("D_003F86A0");
extern char D_003FA1C0[];
extern volatile int D_003F866C;
extern int D_003F866Cn __asm__("D_003F866C");
extern int func_00398EB0(int);

#ifdef NONMATCHING
// DRAFT: GAME 0x399B20
// diff: 2 words (or/lw order before SignalSema)
int func_00399B20(void)
{
    int r;
    if (func_00398EB0(0x1E) == 0)
        return 0;
    D_003F86A0v = 8;
    if (sceSifCallRpc(D_003FA1C0, 0x16, 0, 0, 0, D_003F9840, 4, 0, 0) < 0) {
        SignalSema(D_003F866C);
        D_003F86A0v = 0;
        return 0;
    }
    D_003F86A0v = 0;
    r = *(int *)((unsigned)D_003F9840 | 0x20000000);
    SignalSema(D_003F866Cn);
    return r;
}
#endif

extern char D_0045E610[];
extern void func_0039AB20(int, int *);

#ifdef NONMATCHING
// DRAFT: GAME 0x39C2C8
// diff: 7 words (arg load vs MMIO store order)
void func_0039C2C8(char *s)
{
    int t[8], en, h;
    func_0039C390(s, D_0045E610);
    t[0] = 2;
    func_0039AB20(F(s, 0x868), t);
    h = F(s, 0x868);
    R32(0x10002010) = 0x40000000;
    t[0] = 3;
    func_0039AB20(h, t);
    en = func_003B63A0();
    R32(0x1000F590) = R32(0x1000F520) | 0x10000;
    R32(0x1000B000) = 0;
    R32(0x1000F590) = R32(0x1000F520) & 0xFFFEFFFF;
    if (en)
        func_003B63F0();
    R32(0x1000B020) = 0;
}
#endif

extern int D_003F8674;

struct SemaP {
    int count;
    int max;
    int init;
    int wait;
    int attr;
    char *opt;
};
extern int D_003F8668, D_003F8670, D_003F8660;
extern char D_0045E1A8[], D_0045E1B8[], D_0045E1C8[], D_0045E1D8[];
extern int CreateSema(void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x398638
// diff: 5 words (sp.init=0 store scheduling, tail address regs)
void func_00398638(void)
{
    struct SemaP sp;
    if (D_003F8668 == -1 || D_003F866Cn == -1 || D_003F8670 == -1) {
        sp.init = 1;
        sp.opt = D_0045E1A8;
        sp.max = 1;
        D_003F8668 = CreateSema(&sp);
        sp.opt = D_0045E1B8;
        D_003F866Cn = CreateSema(&sp);
        sp.opt = D_0045E1C8;
        D_003F8670 = CreateSema(&sp);
        sp.opt = D_0045E1D8;
        sp.init = 0;
        D_003F8660 = CreateSema(&sp);
        D_003F8674 = 0;
    }
}
#endif

extern int *D_003F8590[];
extern int D_0045DFE0[];
extern void func_003970C8(void *, int);
extern void func_00397208(void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x397128
// diff: 4 words (init order of table pointers, li 1 reg)
int func_00397128(int mode)
{
    int buf[5];
    int old = R32(0x1000E000) & 1;
    int i;
    int *flag = D_0045DFE0;
    int **pp = D_003F8590;
    for (i = 9; i >= 0; i--, flag++) {
        if (*flag) {
            int *q = *pp;
            q[0] = 0;
            q[0xC] = 0;
            q[4] = 0;
            q[0x14] = 0;
            q[0x10] = 0;
            q[0x20] = 0;
        }
        pp++;
    }
    {
        volatile unsigned int *e = (volatile unsigned int *)0x1000E010;
        unsigned int v;
        *e = 0xFF1F;
        v = *e & 0xFF1F0000;
        *(unsigned int *)e = v;
    }
    func_003970C8(buf, 0x14);
    func_00397208(buf);
    if (mode == 1)
        R32(0x1000E000) |= 1;
    return old;
}
#endif

struct Pk {
    long v;
} __attribute__((packed));

#ifdef NONMATCHING
// DRAFT: GAME 0x399CB0
// diff: 2 words (or/sdl order)
int sceCdReadClock(unsigned char *clock)
{
    int r;
    int *q;
    if (func_00398EB0(0xF) == 0)
        return 0;
    if (sceSifCallRpc(D_003FA1C0, 1, 0, 0, 0, D_003F9840, 0x10, 0, 0) < 0) {
        SignalSema(D_003F866Cn);
        return 0;
    }
    ((struct Pk *)clock)->v = ((struct Pk *)((unsigned)(D_003F9840 + 1) | 0x20000000))->v;
    q = (int *)((unsigned)D_003F9840 | 0x20000000);
    r = *q;
    SignalSema(D_003F866Cn);
    return r;
}
#endif

