extern "C" void func_001FC7F8(void *);
extern "C" void func_001FCDB8(unsigned);
extern "C" void func_001FCDE8(int);
extern char D_00569B80[];
extern char D_0056C380[];

// FUNCTION: GAME 0x1FDEA8
extern "C" void func_001FDEA8(unsigned arg0) {
    unsigned p = arg0;
    do {
        func_001FCDB8(p);
        p += 0x60;
    } while (p < arg0 + 0x3C00);
    unsigned i = 0;
    do {
        func_001FCDE8(arg0 + 0x3C00 + i * 0x70);
        i += 1;
    } while (i < 0x100);
    char *t1 = (char *)(arg0 + 0xAC60);
    char *t0 = (char *)(arg0 + 0xAC00);
    t0[0x49] = 0;
    t1[0x49] = 0;
    unsigned j = 0;
    do {
        char *a = D_00569B80 + j * 0x40;
        func_001FC7F8(a);
        *(unsigned short *)(a + 0x2C) = j;
        j += 1;
    } while (j < 0xA0);
    unsigned k = 0;
    do {
        char *b = D_0056C380 + k * 0x40;
        func_001FC7F8(b);
        *(unsigned short *)(b + 0x2C) = k;
        k += 1;
    } while (k < 0x200);
}
