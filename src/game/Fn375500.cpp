struct Sde3755 {
    char _0[0x84];
    int m84;
    char _88[0xC];
    unsigned m94, m98, m9C, mA0;
};
extern Sde3755 D_0076A790;
extern char D_0076A9C0[0x800];
extern char D_0076B1C0[0x800];

extern "C" {
long func_003B7180();
void func_003B0510(char *, char *);
void func_003758E8(int);
void func_003B7590(unsigned long, unsigned *, unsigned *);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x375500
// 7 words: lui/addiu for D_0076A9C0/B1C0 scheduled after lw s2 via v0 in original; tried struct/array/char* locals, non-volatile
extern "C" void func_00375500()
{
    unsigned buf[2];
    Sde3755 *d = &D_0076A790;
    d->m84 = 0;
    int t0 = (int)func_003B7180();
    unsigned c0 = *(volatile unsigned *)0x10000800;
    func_003B0510(D_0076A9C0, &D_0076A9C0[0x7FF]);
    func_003B0510(D_0076B1C0, &D_0076B1C0[0x7FF]);
    func_003758E8(2);
    unsigned c1 = *(volatile unsigned *)0x10000800;
    int t1 = (int)func_003B7180();
    if (c1 < c0)
        d->m94 = 0;
    else
        d->m94 = c1 - c0;
    func_003B7590((unsigned long)(unsigned)(t1 - t0), buf, &buf[1]);
    d->m9C = buf[1];
    if (d->m98 < d->m94)
        d->m98 = d->m94;
    if (d->m9C > d->mA0)
        d->mA0 = d->m9C;
}
#endif
