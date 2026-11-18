// COMPILER: ee-gcc2.9-991111
// SCE library small units 0x3B1000-0x3BC000, ee-gcc 2.9-991111 -O2 -G0.

#define MFC0_12 ".set push\n.set noreorder\nmfc0 %0, $12\n.set pop"

extern int D_00781780;
struct H { void (*fn)(int); int arg; };
#ifdef NONMATCHING
// DRAFT: GAME 0x3B3F08 (2 words off: original schedules lui before daddu $s0,$gp)
void func_003B3F08(int a0, struct H *h)
{
    if (h->fn) {
        int sv;
        __asm__ volatile("move %0, $28" : "=r"(sv));
        __asm__ volatile("lw $28, %0" : : "m"(D_00781780));
        h->fn(h->arg);
        __asm__ volatile("move $28, %0" : : "r"(sv));
    }
    __asm__ volatile("sync");
    __asm__ volatile("ei");
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x3B63A0 (8 words off: original returns via a0=0 on the not-enabled path, 80 vs 68 bytes)
int func_003B63A0(void)
{
    int s;
    unsigned t;
    __asm__ volatile(MFC0_12 : "=r"(s));
    s &= 0x10000;
    if (s) {
        do {
            __asm__ volatile("di");
            __asm__ volatile("sync.p");
            __asm__ volatile(MFC0_12 : "=r"(t));
        } while (t & 0x10000);
        return s != 0;
    }
    return 0;
}
#endif

// FUNCTION: GAME 0x3B63F0
int func_003B63F0(void)
{
    int s;
    __asm__ volatile(MFC0_12 : "=r"(s));
    s &= 0x10000;
    __asm__ volatile("ei");
    return s != 0;
}

extern void func_003B6408(void);
extern void func_003B6500(void);
extern void func_003B68B8(void);
extern void func_003B6A30(int);
extern void func_003B6B90(void);
extern void func_003B0950(void);
extern void func_003B6738(void);
extern void func_003B7B40(void);
extern void func_003B7988(void);
// FUNCTION: GAME 0x3B6610
void func_003B6610(void)
{
    func_003B6408();
    func_003B6500();
    func_003B68B8();
    func_003B6A30(2);
    func_003B6B90();
    func_003B0950();
    func_003B6738();
    func_003B7B40();
    func_003B7988();
}

extern int D_003FAEF4;
extern int D_00781840;
extern char D_007817C0[];
extern int D_00781800;
extern int sceSifCallRpc();
// FUNCTION: GAME 0x3B5968
int func_003B5968(int a)
{
    int buf[4];
    if (D_003FAEF4 >= 0) {
        D_00781840 = a;
        buf[0] = 0;
        if (sceSifCallRpc(D_007817C0, 1, 0, &D_00781840, 4, &D_00781800, 4, 0) >= 0)
            return D_00781800;
    }
    return 0;
}

// FUNCTION: GAME 0x3B59D8
int func_003B59D8(int a)
{
    int buf[4];
    if (D_003FAEF4 < 0)
        return 0;
    D_00781840 = a;
    buf[0] = 0;
    if (sceSifCallRpc(D_007817C0, 2, 0, &D_00781840, 4, &D_00781800, 4, 0) >= 0)
        return D_00781800;
    return -1;
}
