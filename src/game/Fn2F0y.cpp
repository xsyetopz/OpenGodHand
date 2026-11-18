// Near-miss drafts for small units in 0x2F0000-0x320000 (ee-gcc2.95.3-136, C++).
#ifdef NONMATCHING
extern int D_00753D88;
extern int D_00747A18;
extern char Snd[];
extern "C" void func_002CA690(void *);

struct Slot {
    char pad[8];
    unsigned char used;
    char rest[15];
};

// DRAFT: GAME 0x306F88
// diff: 14 words (tried for/while/continue/break forms, uchar k, decl order: 14-16); original keeps the constant 1 in a1 before the loop and enters the body with no first range test, mine tests used with beql and builds 1 inside the loop
extern "C" Slot *func_00306F88(Slot *p)
{
    Slot *end = p + 32;
    int k = 1;
    do {
        if (p->used == 0) {
            p->used = k;
            return p;
        }
    } while (++p < end);
    return 0;
}

// DRAFT: GAME 0x30D190
// diff: 6 words; the counter and flag loads take other registers (original: lui a1/a0, lw v0/v1; mine lui v0, lw a0/v1) Also tried: single-expression forms, load/store reorders, no asm (18 words).
extern "C" int func_0030D190()
{
    int c = D_00753D88;
    int f = D_00747A18;
    D_00753D88 = c + 1;
    int t = f ^ 1;
    __asm__("" : "+r"(t));
    if (!t)
        func_002CA690(Snd);
    *(volatile unsigned *)0x10000010 |= 0x400;
    __asm__ volatile("sync");
    __asm__ volatile("ei");
    return 0;
}
#endif
