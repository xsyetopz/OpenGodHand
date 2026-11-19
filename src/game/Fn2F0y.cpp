// Units in 0x2F0000-0x320000 (ee-gcc2.95.3-136, C++).
struct Slot {
    char pad[8];
    unsigned char used;
    char rest[15];
};

// FUNCTION: GAME 0x306F88
extern "C" Slot *func_00306F88(Slot *p)
{
    Slot *end = p + 32;
    int k = 1;
    do {
        if (p->used != 0) {
            p++;
        } else {
            p->used = k;
            return p;
        }
    } while (p < end);
    return 0;
}

#ifdef NONMATCHING
extern int D_00753D88;
extern int D_00747A18;
extern char Snd[];
extern "C" void func_002CA690(void *);

// DRAFT: GAME 0x30D190
// diff: 2 words; the store of D_00753D88 lands before the xori in the original, after it in the draft. Tried: store positions, barrier placement, f barrier, nc barrier after the store, plus a 6-word plain form and a no-asm form (18 words).
extern "C" int func_0030D190()
{
    int c = D_00753D88;
    __asm__("" : "+r"(c));
    int nc = c + 1;
    __asm__("" : "+r"(nc));
    int f = D_00747A18;
    D_00753D88 = nc;
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
