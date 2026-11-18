extern unsigned D_0071B7C0[], D_0071B840[], D_0071B8C0[];
extern char D_0061B7C0[];

struct VT {
    char pad[0x30];
    short adj;
    short pad2;
    void (*fn)(char *, int);
};

// DRAFT: GAME 0x2FBA60
#ifdef NONMATCHING
extern "C" void func_002FBA60(int a, int b, int c)
{
    char *p = D_0061B7C0;
    unsigned i = 0;
    do {
        int off = (i >> 5) * 4;
        unsigned m = 0x80000000u >> (i & 0x1F);
        if ((*(unsigned *)((char *)D_0071B7C0 + off) & m) && !(*(unsigned *)((char *)D_0071B840 + off) & m)
            && !(*(unsigned *)((char *)D_0071B8C0 + off) & m) && *(int *)(p + 0x10C) == b
            && *(int *)(p + 0x108) == a) {
            VT *v = *(VT **)(p + 0xF0);
            v->fn(p + v->adj, c & 0xFF);
        }
        i++;
        p += 0x400;
    } while ((int)i < 0x400);
}
#endif
