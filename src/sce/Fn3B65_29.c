// COMPILER: ee-gcc2.9-991111
extern int D_003FAF08[4];
extern unsigned D_003FAF00;
extern void func_003B6600(int, int);
extern unsigned func_003B64E8(unsigned, unsigned, void *);
extern void func_003B64A8(void), func_003B6468(void);
// FUNCTION: GAME 0x3B6500
void func_003B6500(void)
{
    unsigned a, b, x, y;
    func_003B6600(D_003FAF08[0], D_003FAF08[1]);
    func_003B6600(D_003FAF08[2], D_003FAF08[3]);
    a = func_003B64E8(0x80000000, 0x80080000, func_003B64A8);
    b = func_003B64E8(0x80000000, 0x80080000, (char *)func_003B6468 + 8);
    x = a - 0x20C;
    y = b - 0x168;
    while (x != y) {
        if (x < y) {
            a = func_003B64E8(a + 4, 0x80080000, func_003B64A8);
            x = a - 0x20C;
        } else {
            b = func_003B64E8(b + 4, 0x80080000, (char *)func_003B6468 + 8);
            y = b - 0x168;
        }
    }
    D_003FAF00 = x;
}
