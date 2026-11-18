// Medium integer units of the damage and data managers in 0x1F0000-0x200000.
extern unsigned char D_00569B80[];
extern unsigned char D_0056C380[];
extern char g_DmgManage[];
extern "C" void func_001FC7C8(void *);
extern "C" void func_001FDE00(void *);
extern "C" int func_001FEE00(void *);
extern "C" int func_001FEC90(void *, int);
extern "C" int func_001FEEA0(void *);
extern "C" void func_001FF470(void *, int, int);

// FUNCTION: GAME 0x1FE428
extern "C" void func_001FE428(int a, int b)
{
    if (b == 0xFFFF && a) {
        int i, j;
        unsigned char *p = D_00569B80;
        for (i = 0x9F; i != -1; i--) { func_001FC7C8(p); p += 0x40; }
        unsigned char *q = D_0056C380;
        for (j = 0x1FF; j != -1; j--) { func_001FC7C8(q); q += 0x40; }
        func_001FDE00(g_DmgManage);
    }
}

// FUNCTION: GAME 0x1FECE0
extern "C" int func_001FECE0(char *self, int a, int b)
{
    if (func_001FEE00(self) >= 0)
        func_001FEC90(self, a);
    int i = func_001FEEA0(self);
    if (i < 0)
        return 0;
    int off = i * 0x5C;
    func_001FF470(*(char **)(self + 8) + off, a, b);
    *(int *)(off + *(int *)(self + 8) + 4) = -100;
    return 1;
}
