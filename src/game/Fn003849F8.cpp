extern "C" void func_002E0DE8(int, int, int, const char *, ...);
extern char D_0045CCB0[];
extern char D_0045CCD0[];
extern char D_0045CCE0[];
extern char D_0045CCF0[];
extern char D_0045CD10[];
extern char D_0045CD28[];

struct Fn384Q {
    char _p0[8];
    short a[5];
    short b[5];
    short c[5];
    short d[5];
};

// FUNCTION: GAME 0x3849F8
extern "C" void func_003849F8(int, Fn384Q *p, unsigned char n)
{
    if (n == 0) {
        func_002E0DE8(3, 0x15, 8, D_0045CCB0, p->a[0], p->b[0]);
        func_002E0DE8(3, 0x16, 8, D_0045CCD0, p->c[0]);
        func_002E0DE8(3, 0x17, 8, D_0045CCE0, p->d[0]);
        return;
    }
    int k = n - 1;
    func_002E0DE8(3, 0x15, 8, D_0045CCF0, k, p->a[n], p->b[n]);
    func_002E0DE8(3, 0x16, 8, D_0045CD10, k, p->c[n]);
    func_002E0DE8(3, 0x17, 8, D_0045CD28, k, p->d[n]);
}
