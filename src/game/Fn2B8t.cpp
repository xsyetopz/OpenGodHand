extern "C" void func_002B4768(void *, int *, int *);
extern "C" void func_002B33D8(char *);
extern "C" int func_002B34D8(char *);

// FUNCTION: GAME 0x2B3338
extern "C" void func_002B3338(char *self)
{
    int *p = (int *)self;
    while (p[0x90 / 4] <= p[0x68 / 4] && (unsigned char)self[0xC] == 2 && ({
        if (!(*(unsigned short *)p[0x8C / 4] >> 15))
            func_002B33D8(self);
        else if (func_002B34D8(self))
            goto set;
        1; }))
        func_002B4768(self, p + 0x90 / 4, p + 0x8C / 4);
    return;
set:
    p[0x68 / 4] = p[0x90 / 4];
}

#ifdef NONMATCHING
// DRAFT: GAME 0x2BE458
// diff: 2 words, sw 0x4C0(s1) scheduled before a3=sp
extern "C" void *memset(void *, int, unsigned);
extern "C" void func_00398B90(char *, char *);
extern "C" void func_00399728(int, unsigned, void *, char *);
extern "C" void func_00398DA0(int);
extern "C" void *_MemoryAlloc__FUiUiR5cHeap(unsigned, unsigned, void *);
extern char D_0044C0B8[];
extern void *MemDefalutHeapPtr;
extern "C" void func_002BE458(char *self)
{
    char buf[0x40];
    memset(buf, 0, 4);
    buf[1] = 1;
    func_00398B90(buf + 0x10, D_0044C0B8);
    unsigned n = (*(unsigned *)(buf + 0x14) + 0x7FF) >> 11;
    void *m = _MemoryAlloc__FUiUiR5cHeap(n << 11, 0x40, MemDefalutHeapPtr);
    func_00399728(*(int *)(buf + 0x10), n, *(void **)(self + 0x4C0) = m, buf);
    func_00398DA0(0);
}
#endif
