// COMPILER: ee-gcc2.9-991111
// SCE library small units 0x3A4AF0-0x3B1000, ee-gcc 2.9-991111 -O2 -G0.

extern int D_003FAE40;
extern int func_001F6E68(int);
extern int func_001F6E98(int, int);

// FUNCTION: GAME 0x3B0120
void func_003B0120(void)
{
    D_003FAE40 = 0;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x3B0268 (9 words off: s0/s1 swapped, original keeps D_003FAE40 base in s0 and arg in s1)
int func_003B0268(int fd, int a, int b)
{
    if ((unsigned int)(fd - 1) < 2) {
        if (D_003FAE40 == 0) {
            if (func_001F6E68(a) == 0)
                return -1;
            D_003FAE40 = 1;
        }
        return func_001F6E98(a, b);
    }
    return -1;
}
#endif

extern void func_003B63A0(void);
extern void func_003B63F0(void);
// TagLo read without the assembler's hazard nop; the original has none.
#define MFC0 ".set push\n.set noreorder\nmfc0 %0, $28\n.set pop"

// FUNCTION: GAME 0x3B0468
void func_003B0468(unsigned a, unsigned b)
{
    int i;
    unsigned t;
    for (i = 0; i < 0x1000; i += 0x40) {
        __asm__ volatile("sync");
        __asm__ volatile("cache 0x10, 0(%0)" : : "r"(i));
        __asm__ volatile("sync");
        __asm__ volatile(MFC0 : "=r"(t));
        t = (t & 0xFFFFF000u) + i;
        if (!(t < a) && !(b < t)) {
            __asm__ volatile("sync");
            __asm__ volatile("cache 0x14, 0(%0)" : : "r"(i));
            __asm__ volatile("sync");
        }
        __asm__ volatile("sync");
        __asm__ volatile("cache 0x10, 1(%0)" : : "r"(i));
        __asm__ volatile("sync");
        __asm__ volatile(MFC0 : "=r"(t));
        t = (t & 0xFFFFF000u) + i;
        if (!(t < a) && !(b < t)) {
            __asm__ volatile("sync");
            __asm__ volatile("cache 0x14, 1(%0)" : : "r"(i));
            __asm__ volatile("sync");
        }
        __asm__ volatile("sync");
    }
}

// FUNCTION: GAME 0x3B0598
void func_003B0598(unsigned a, unsigned b)
{
    int i;
    unsigned t;
    for (i = 0; i < 0x1000; i += 0x40) {
        __asm__ volatile("sync");
        __asm__ volatile("cache 0x10, 0(%0)" : : "r"(i));
        __asm__ volatile("sync");
        __asm__ volatile(MFC0 : "=r"(t));
        t = (t & 0xFFFFF000u) + i;
        if (!(t < a) && !(b < t)) {
            __asm__ volatile("sync");
            __asm__ volatile("cache 0x16, 0(%0)" : : "r"(i));
            __asm__ volatile("sync");
        }
        __asm__ volatile("sync");
        __asm__ volatile("cache 0x10, 1(%0)" : : "r"(i));
        __asm__ volatile("sync");
        __asm__ volatile(MFC0 : "=r"(t));
        t = (t & 0xFFFFF000u) + i;
        if (!(t < a) && !(b < t)) {
            __asm__ volatile("sync");
            __asm__ volatile("cache 0x16, 1(%0)" : : "r"(i));
            __asm__ volatile("sync");
        }
        __asm__ volatile("sync");
    }
}

// FUNCTION: GAME 0x3B0510
void func_003B0510(unsigned a, unsigned b)
{
    int s;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s));
    s &= 0x10000;
    if (s)
        func_003B63A0();
    func_003B0468(a & 0xFFFFFFC0u, b & 0xFFFFFFC0u);
    if (s)
        func_003B63F0();
}

// FUNCTION: GAME 0x3B0640
void func_003B0640(unsigned a, unsigned b)
{
    int s;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s));
    s &= 0x10000;
    if (s)
        func_003B63A0();
    func_003B0598(a & 0xFFFFFFC0u, b & 0xFFFFFFC0u);
    if (s)
        func_003B63F0();
}
