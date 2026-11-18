extern "C" void func_002D4C20(int, int, int, int);

// FUNCTION: GAME 0x2D4B08
extern "C" void func_002D4B08(int a0, int a1, int a2, int a3, int a4, int a5)
{
    int fp = a2 / 16;
    int s6 = a3 / 16;
    int a = 0;
    int sp0 = a1;
    int sp4 = a4;
    int sp8 = a5;
    if (fp > 0) {
        int spC = a3 << 6;
        do {
            int d = sp4 + (a << 6);
            int s = sp0 + spC * a;
            if (s6 > 0) {
                int c = s6;
                do {
                    func_002D4C20(a0, d, s, a2);
                    s += 0x400;
                    c -= 1;
                    d += sp8 * 0x10;
                } while (c != 0);
            }
            a += 1;
        } while (a < fp);
    }
}
