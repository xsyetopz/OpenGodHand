// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// Unnamed printf-style wrappers in 0x2E0000-0x2EFFFF.
extern "C" int func_002E0AD8(int);
extern "C" int func_002E0AE0(int);
extern "C" int func_002E0B18(int, int);
extern "C" void func_002E0F18(char *, int, int, int, int);
extern "C" int vsprintf(char *, const char *, void *);
extern "C" char D_0061B298[];

// FUNCTION: GAME 0x2E0C80
extern "C" void func_002E0C80(int a, int b, int c, int d, int e, const char *fmt, void *ap)
{
    if (func_002E0AD8(d))
        return;
    if (func_002E0AE0(b))
        return;
    int n = vsprintf(D_0061B298, fmt, ap);
    if (n + 1 >= 0x200)
        *(int *)0x11111111 = 0;
    if (func_002E0B18(a, n))
        return;
    func_002E0F18(D_0061B298, a, b, c, e);
}

extern "C" void Moji_size_set__FUcUc(unsigned char, unsigned char);

// FUNCTION: GAME 0x2E0B78
extern "C" void func_002E0B78(int a, int b, int c, int d, int e, int f, int g, const char *fmt, void *ap)
{
    if (func_002E0AD8(f))
        return;
    if (func_002E0AE0(d))
        return;
    Moji_size_set__FUcUc(a, b);
    int n = vsprintf(D_0061B298, fmt, ap);
    if (n + 1 >= 0x200)
        *(int *)0x11111111 = 0;
    if (func_002E0B18(c, n))
        return;
    func_002E0F18(D_0061B298, c, d, e, g);
    Moji_size_set__FUcUc(0, 0);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x2E0DE8
// diff (15 words): va_start via __builtin_next_arg gives sp+0xD0 where original has sp+0xB0; DISPLAY_W/cw swap s3/s4
typedef void *va_list;
#define va_start(AP, L) ((AP) = (va_list)__builtin_next_arg(L))
extern "C" int vsprintf(char *, const char *, va_list);
extern "C" int DISPLAY_W, DISPLAY_H;
extern "C" void func_002E0DE8(int x, int y, int z, const char *fmt, ...)
{
    int px = (x << 19) >> 16;
    int py = (y << 19) >> 16;
    va_list ap;
    int n, i, cw = 8;
    va_start(ap, fmt);
    if (py < -8)
        return;
    if (DISPLAY_H * 2 + 8 < py)
        return;
    if (px >= DISPLAY_W)
        return;
    n = vsprintf(D_0061B298, fmt, ap);
    if (n + 1 >= 0x200)
        *(int *)0x11111111 = 0;
    if ((DISPLAY_W - px) < n * cw) {
        i = (DISPLAY_W - px) / cw;
        if (i < 0)
            return;
        D_0061B298[i] = 0;
    }
    func_002E0F18(D_0061B298, px, py, z, 0);
}
#endif
