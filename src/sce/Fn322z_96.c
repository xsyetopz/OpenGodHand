// COMPILER: ee-gcc2.96
// FUNCTION: GAME 0x32B758
extern int func_0033E8A0();
int func_0032B758(unsigned short *p, int n, int *out)
{
    short a; char b, c, d, e; int f, g, h;
    if (n < 2) return 0;
    if ((unsigned short)((*p << 8) | (*p >> 8)) != 0x8000) return 0;
    if (func_0033E8A0(p, n, &a, &b, &c, &d, &e, &f, &g, &h) < 0) return 0;
    *out = a;
    return 1;
}
