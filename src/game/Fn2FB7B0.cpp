extern "C" {
void func_002FBE50(void *, int);
}
extern unsigned D_0071B7C0[], D_0071B840[], D_0071B8C0[];
extern char D_0061B7C0[];

#ifdef NONMATCHING
// DRAFT: GAME 0x2FB7B0  ~44 words; same as 2FB6C8 (i++ placement, mask reg)
extern "C" void func_002FB7B0(int a) {
    char *p = D_0061B7C0;
    unsigned i = 0;
    do {
        unsigned m = 0x80000000u >> (i & 0x1F);
        int w = (i >> 5) * 4;
        if ((*(unsigned *)((char *)D_0071B7C0 + w) & m) && !(*(unsigned *)((char *)D_0071B840 + w) & m) &&
            !(*(unsigned *)((char *)D_0071B8C0 + w) & m) && (*(int *)(p + 0x104) & a))
            func_002FBE50(p, w);
        i++;
        p += 0x400;
    } while ((int)i < 0x400);
}
#endif
