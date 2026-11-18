// Fn00171140: set flag bits on five rows of six entries.
extern "C" void func_001B6FB8();
extern "C" void func_001717C0(void *, int, void *);
extern unsigned char D_004209E8[];

#ifdef NONMATCHING
static inline unsigned char inRange(char *p, int i) {
    unsigned char n = *(unsigned char *)(p + 0x2B4);
    unsigned char r = 0;
    if (i >= 0) r = i < n;
    return r;
}

// DRAFT: GAME 0x00171140
// 41 words differ: original keeps a zero reg (slt idx,0) and spills count to stack (frame 0x30), range check via slt/andi not movn; tried && form, if-form, inline helper, do-while loops
extern "C" int func_00171140(char *p) {
    func_001B6FB8();
    func_001717C0(p, *(int *)(p + 0xF0), p + 0x100);
    int i = 0;
    do {
        int idx = D_004209E8[i];
        int j = 5;
        i++;
        do {
            char *e = inRange(p, idx) ? ((char **)*(char **)(p + 0x278))[idx] : 0;
            idx++;
            *(unsigned *)(e + 0x154) |= 0x18;
        } while (--j >= 0);
    } while (i < 5);
    return 1;
}
#endif
