extern unsigned D_0071B7C0[], D_0071B840[], D_0071B8C0[];
extern char D_0061B7C0[];

struct VT {
    char pad[0x30];
    short adj;
    short pad2;
    void (*fn)(char *, int);
};

// DRAFT: GAME 0x2FBA60
// Prologue and hoisted constants match; remaining diff is i++ scheduling (original keeps it in bnel delay slots, ours hoists it above srlv, mask in v1 not a0). Tried do-while, for loop, hoisted table pointers, hoisted c & 0xFF, addu operand order.
#ifdef NONMATCHING
extern "C" void func_002FBA60(int a, int b, int c)
{
    char *t0 = (char *)D_0071B7C0;
    char *t1 = (char *)D_0071B840;
    char *t2 = (char *)D_0071B8C0;
    int cc = c & 0xFF;
    char *p = D_0061B7C0;
    unsigned i;
    for (i = 0; (int)i < 0x400; i++, p += 0x400) {
        int off = (i >> 5) * 4;
        unsigned m = 0x80000000u >> (i & 0x1F);
        if ((*(unsigned *)(off + (int)t0) & m) && !(*(unsigned *)(off + (int)t1) & m)
            && !(*(unsigned *)(off + (int)t2) & m) && *(int *)(p + 0x10C) == b
            && *(int *)(p + 0x108) == a) {
            VT *v = *(VT **)(p + 0xF0);
            v->fn(p + v->adj, cc);
        }
    }
}
#endif
