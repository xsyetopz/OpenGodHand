// Small field setters and accessors in 0x2B5000-0x2BFFFF.
extern const char D_0044BED0[];
extern int D_00747A80;

struct sU2B {
    char _p0[0x70];
    int m_70;
    char _p74[0x90 - 0x74];
    int m_90;
    char _p94[0x100 - 0x94];
    const void *m_100;
    float m_104;
    char _p108[0x110 - 0x108];
    float m_110;
};
struct sU2Bw {
    int m_0;
    int m_4;
};
struct sU2Bz {
    int m_0;
    char m_4;
};
struct sU2Bi {
    int m_0;
    int m_4;
    int _p8[2];
    int m_10;
};

extern "C" {
// FUNCTION: GAME 0x2B5AE8
void func_002B5AE8(sU2Bw *s)
{
    s->m_0 = 0;
    s->m_4 = 0;
}
// FUNCTION: GAME 0x2B6510
int func_002B6510(sU2B *s)
{
    return s->m_90 != 0;
}
// FUNCTION: GAME 0x2BA570
void func_002BA570(sU2B *s)
{
    float *p = (float *)((char *)s + 0xE4);
    *p = s->m_110;
}
// FUNCTION: GAME 0x2BA4D8
void func_002BA4D8(sU2B *s)
{
    s->m_100 = D_0044BED0;
}
// FUNCTION: GAME 0x2BA580
void func_002BA580(sU2B *s)
{
    s->m_100 = D_0044BED0;
}
// FUNCTION: GAME 0x2BA6E8
void func_002BA6E8(sU2B *s)
{
    s->m_100 = D_0044BED0;
}
// FUNCTION: GAME 0x2BA818
void func_002BA818(sU2B *s)
{
    s->m_100 = D_0044BED0;
}
// FUNCTION: GAME 0x2BA8D0
void func_002BA8D0(sU2B *s)
{
    s->m_100 = D_0044BED0;
}
// FUNCTION: GAME 0x2BA938
void func_002BA938(sU2B *s)
{
    s->m_100 = D_0044BED0;
}
// FUNCTION: GAME 0x2BAA30
void func_002BAA30(sU2B *s)
{
    s->m_100 = D_0044BED0;
}
// FUNCTION: GAME 0x2BE550
sU2Bz *func_002BE550(sU2Bz *s)
{
    s->m_0 = 0;
    s->m_4 = 0;
    return s;
}
// FUNCTION: GAME 0x2BF780
void func_002BF780(sU2B *s)
{
    D_00747A80 = s->m_70;
}
// FUNCTION: GAME 0x2BA1B0
int func_002BA1B0(sU2Bi *s)
{
    s->m_0 = 0;
    s->m_4 = 0;
    s->m_10 = 0;
    return 1;
}
}
